%% @doc The glpkerl application.  It must be started before any of the 
%% functions provided by this library can be used.
%% @end

-module (glpkerlapp).
-export ([ start/0,
           stop/0 ]).
-behaviour (application).
-export ([ start/2,
           stop/1 ]).

%-=====================================================================-
%-                                Public                               -
%-=====================================================================-

%% @spec start () -> ok | { error, Reason }
%% @equiv application:start (glpkerl)
%% @end

start () ->
  application:start (glpkerl).

%% @spec stop () -> ok | { error, Reason }
%% @equiv application:stop (glpkerl)
%% @end

stop () ->
  application:stop (glpkerl).

%-=====================================================================-
%-                        application callbacks                        -
%-=====================================================================-

%% @hidden

start (_Type, _Args) ->
  glpksup:start_link ().

%% @hidden

stop (_Args) ->
  ok.
