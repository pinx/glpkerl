%% @hidden

-module (glpksup).
-behaviour (supervisor).

-export ([ start_link/0, 
           init/1,
           sup_upgrade_notify/2 ]).

%-=====================================================================-
%-                                Public                               -
%-=====================================================================-

start_link () ->
  supervisor:start_link ({ local, ?MODULE }, ?MODULE, []).

init ([]) ->
  { ok, 
    { { one_for_one, 3, 10 }, 
      [
        { glpksrv,
          { glpksrv, start_link, [] },
          permanent,
          5000,
          worker,
          [ glpksrv ] 
        }
      ] 
    } 
  }.

sup_upgrade_notify (_Old, _New) ->
  { ok, { _, Specs } } = init ([]),
  
  Old = sets:from_list (
          [ Name || { Name, _, _, _ } <- supervisor:which_children (?MODULE) ]),
  New = sets:from_list ([ Name || { Name, _, _, _, _, _ } <- Specs ]),
  Kill = sets:subtract (Old, New),
  
  sets:fold (fun (Id, ok) ->
               supervisor:terminate_child (?MODULE, Id),
               supervisor:delete_child (?MODULE, Id),
               ok
             end, 
             ok, 
             Kill),
  
  [ supervisor:start_child (?MODULE, Spec) || Spec <- Specs ],
  ok.
