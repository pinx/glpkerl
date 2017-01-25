%% @hidden

-module (glpksrv).
-export ([ reload_driver/0,
           start_link/0 ]).

-behaviour (gen_server).
-export ([ init/1,
           handle_call/3,
           handle_cast/2,
           handle_info/2,
           code_change/3,
           terminate/2 ]).

-include ("glpkerlprefix.hrl").

-record (state, {}).

%-=====================================================================-
%-                                Public                               -
%-=====================================================================-

reload_driver ()->
  gen_server:cast (?MODULE, reload_driver).

start_link () ->
  gen_server:start_link ({ local, ?MODULE }, ?MODULE, [], []).

%-=====================================================================-
%-                         gen_server callbacks                        -
%-=====================================================================-

init ([]) ->
  process_flag (trap_exit, true),

  { ok, DirVar } = application:get_env (glpkerl, glpkdrvprefix),
  Dir = case DirVar of auto_detect -> glpkerldrv_guessprefix (); _ -> DirVar end,

  case erl_ddll:load_driver (Dir ++ "/lib", "libglpkerldrv") of
    ok -> ok;
    { error, already_loaded } -> ok
  end,

  { ok, #state {} }.

handle_call (_Msg, _From, State) ->
  { noreply, State }.

handle_cast (reload_driver, State = #state {}) ->
  { ok, DirVar } = application:get_env (glpkerl, glpkdrvprefix),
  Dir = case DirVar of auto_detect -> glpkerldrv_guessprefix (); _ -> DirVar end,

  case erl_ddll:reload_driver (Dir ++ "/lib", "libglpkerldrv") of
    ok -> 
      ok;
    { error, ErrorDesc } -> 
      error_logger:error_msg ("Failed to reload libglpkerldrv: ~p~n", [ ErrorDesc ]),
      ok
  end,

  { noreply, State#state {} };
handle_cast (_Msg, State) ->
  { noreply, State }.

handle_info (_Msg, State) ->
  { noreply, State }.

code_change (_Vsn, State, _Extra) ->
  { ok, State }.

terminate (_Reason, #state {}) ->
  ok.

%-=====================================================================-
%-                               Private                               -
%-=====================================================================-

glpkerldrv_guessprefix () ->
  lists:foldl 
    (fun (Candidate, undefined) ->
       case file:read_file_info (Candidate ++ "/lib/libglpkerldrv.so") of
         { ok, _ } -> Candidate;
         { error, _ } -> undefined
       end;
         (_, Acc) ->
       Acc
     end,
     undefined,
     [ ?automake_prefix, "/usr", "/usr/local", "/sw" ]).
