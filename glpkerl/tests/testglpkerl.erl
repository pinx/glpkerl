-module (testglpkerl).

-ifdef (HAVE_EUNIT).
-include_lib ("eunit/include/eunit.hrl").
-endif.

-ifdef (EUNIT).

% corresponds to spxsamp1.c

spxsamp1_test_ () ->
  [
    { setup,
      fun () ->
        glpkerl:stop (),
        glpkerl:start ()
      end,
      fun (_) ->
        glpkerl:stop ()
      end,
      fun () ->
        { ok, Lp } = glpkerl:new (LinkedIn),
        0 = glpkerl:read_mps (Lp, 'glp_mps_deck', "25fv47.mps"),
        ok = glpkerl:adv_basis (Lp),
        glp_success = glpkerl:simplex (Lp, []),
        0 = glpkerl:print_sol (Lp, "25fv47.txt")
      end
    }
    || LinkedIn <- [ true, false ]
  ].

% corresponds to iptsamp.c

interior_test_ () ->
  [
    { setup,
      fun () ->
        glpkerl:stop (),
        glpkerl:start ()
      end,
      fun (_) ->
        glpkerl:stop ()
      end,
      fun () ->
        { ok, Lp } = glpkerl:new (LinkedIn),
        0 = glpkerl:read_mps (Lp, 'glp_mps_deck', "25fv47.mps"),
        glp_success = glpkerl:interior (Lp, []),
        0 = glpkerl:print_sol (Lp, "25fv47.txt")
      end
    }
    || LinkedIn <- [ true, false ]
  ].

% corresponds to sample.c

sample_test_ () ->
  [
    { setup,
      fun () ->
        glpkerl:stop (),
        glpkerl:start ()
      end,
      fun (_) ->
        glpkerl:stop ()
      end,
      fun () ->
        { ok, Lp } = glpkerl:new (LinkedIn),
        ok = glpkerl:set_prob_name (Lp, "sample"),
        ok = glpkerl:set_obj_dir (Lp, glp_max),
        1 = glpkerl:add_rows (Lp, 3),
        ok = glpkerl:set_row_name (Lp, 1, "p"),
        ok = glpkerl:set_row_bnds (Lp, 1, glp_up, 0, 100),
        ok = glpkerl:set_row_name (Lp, 2, "q"),
        ok = glpkerl:set_row_bnds (Lp, 2, glp_up, 0, 600),
        ok = glpkerl:set_row_name (Lp, 3, "r"),
        ok = glpkerl:set_row_bnds (Lp, 3, glp_up, 0, 300),
        1 = glpkerl:add_cols (Lp, 3),
        ok = glpkerl:set_col_name (Lp, 1, "x1"),
        ok = glpkerl:set_col_bnds (Lp, 1, glp_lo, 0, 0),
        ok = glpkerl:set_obj_coef (Lp, 1, 10.0),
        ok = glpkerl:set_col_name (Lp, 2, "x2"),
        ok = glpkerl:set_col_bnds (Lp, 2, glp_lo, 0, 0),
        ok = glpkerl:set_obj_coef (Lp, 2, 6.0),
        ok = glpkerl:set_col_name (Lp, 3, "x3"),
        ok = glpkerl:set_col_bnds (Lp, 3, glp_lo, 0, 0),
        ok = glpkerl:set_obj_coef (Lp, 3, 4.0),
        ok = glpkerl:load_matrix (Lp, 
                                  9,
                                  [ 1, 1, 1, 2, 3, 2, 3, 2, 3 ],
                                  [ 1, 2, 3, 1, 1, 2, 2, 3, 3 ],
                                  [ 1, 1, 1, 10, 2, 4, 2, 5, 6 ]),
        glp_success = glpkerl:simplex (Lp, []),
        Z = glpkerl:get_obj_val (Lp),
        X1 = glpkerl:get_col_prim (Lp, 1),
        X2 = glpkerl:get_col_prim (Lp, 2),
        X3 = glpkerl:get_col_prim (Lp, 3),
        true = (abs (Z - 733.333) < 1.0e-3),
        true = (abs (X1 - 33.333) < 1.0e-3),
        true = (abs (X2 - 66.6667) < 1.0e-3),
        true = (abs (X3 - 0) < 1.0e-3)
      end
    }
    || LinkedIn <- [ true, false ]
  ].

-endif.
