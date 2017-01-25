package glpkdrvspec;

use warnings;
use strict;

@glpkdrvspec::spec = (
  { name => 'set_prob_name',
    function => 'glp_set_prob_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'const char*', 'name' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_obj_name',
    function => 'glp_set_obj_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'const char*', 'name' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_obj_dir',
    function => 'glp_set_obj_dir',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ [ 'enum', 'dirtype', [ 'glp_min', 'glp_max' ] ],
                     'dir'
                   ],
                 ],
    return_type => 'void'
  },
  { name => 'add_rows',
    function => 'glp_add_rows',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'nrs' ] 
                 ],
    return_type => 'int32_t'
  },
  { name => 'add_cols',
    function => 'glp_add_cols',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'ncs' ] 
                 ],
    return_type => 'int32_t'
  },
  { name => 'set_row_name',
    function => 'glp_set_row_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ],
                   [ 'const char*', 'name' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_col_name',
    function => 'glp_set_col_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ],
                   [ 'const char*', 'name' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_row_bnds',
    function => 'glp_set_row_bnds',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ],
                   [ [ 'enum', 'boundtype', 
                       [ 'glp_fr', 'glp_lo', 'glp_up', 'glp_db', 'glp_fx' ]
                     ],
                     'type' ],
                   [ 'double', 'lb' ],
                   [ 'double', 'ub' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_col_bnds',
    function => 'glp_set_col_bnds',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ],
                   [ [ 'enum', 'boundtype', 
                       [ 'glp_fr', 'glp_lo', 'glp_up', 'glp_db', 'glp_fx' ]
                     ],
                     'type' ],
                   [ 'double', 'lb' ],
                   [ 'double', 'ub' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_obj_coef',
    function => 'glp_set_obj_coef',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ],
                   [ 'double', 'coeff' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_mat_row',
    function => 'glp_set_mat_row',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ],
                   [ 'int32_t', 'len' ],
                   [ 'const int*', 'ind' ],
                   [ 'const double*', 'val' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_mat_col',
    function => 'glp_set_mat_col',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ],
                   [ 'int32_t', 'len' ],
                   [ 'const int*', 'ind' ],
                   [ 'const double*', 'val' ]
                 ],
    return_type => 'void'
  },
  { name => 'load_matrix',
    function => 'glp_load_matrix',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'ne' ],
                   [ 'const int*', 'ia' ],
                   [ 'const int*', 'ja' ],
                   [ 'const double*', 'ar' ]
                 ],
    return_type => 'void'
  },
  { name => 'del_rows',
    function => 'glp_del_rows',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'nrs' ],
                   [ 'const int*', 'num' ],
                 ],
    return_type => 'void'
  },
  { name => 'del_cols',
    function => 'glp_del_cols',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'ncs' ],
                   [ 'const int*', 'num' ],
                 ],
    return_type => 'void'
  },
  # glp_copy_prob skipped ...
  { name => 'erase_prob',
    function => 'glp_erase_prob',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                 ],
    return_type => 'void'
  },
  # glp_delete_prob skipped ...
  { name => 'get_prob_name',
    function => 'glp_get_prob_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                 ],
    return_type => 'const char*'
  },
  { name => 'get_obj_name',
    function => 'glp_get_obj_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                 ],
    return_type => 'const char*'
  },
  { name => 'get_obj_dir',
    function => 'glp_get_obj_dir',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                 ],
    return_type => [ 'enum', 'dirtype', [ 'glp_min', 'glp_max' ] ],
  },
  { name => 'get_num_rows',
    function => 'glp_get_num_rows',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                 ],
    return_type => 'int32_t'
  },
  { name => 'get_num_cols',
    function => 'glp_get_num_cols',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                 ],
    return_type => 'int32_t'
  },
  { name => 'get_row_name',
    function => 'glp_get_row_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ]
                 ],
    return_type => 'const char*'
  },
  { name => 'get_col_name',
    function => 'glp_get_col_name',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ]
                 ],
    return_type => 'const char*'
  },
  { name => 'get_row_type',
    function => 'glp_get_row_type',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ]
                 ],
    return_type => [ 'enum', 'boundtype', 
                       [ 'glp_fr', 'glp_lo', 'glp_up', 'glp_db', 'glp_fx' ]
                   ]
  },
  { name => 'get_row_lb',
    function => 'glp_get_row_lb',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ]
                 ],
    return_type => 'double'
  },
  { name => 'get_row_ub',
    function => 'glp_get_row_ub',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'i' ]
                 ],
    return_type => 'double'
  },
  { name => 'get_col_type',
    function => 'glp_get_col_type',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ]
                 ],
    return_type => [ 'enum', 'boundtype', 
                       [ 'glp_fr', 'glp_lo', 'glp_up', 'glp_db', 'glp_fx' ]
                   ]
  },
  { name => 'get_col_lb',
    function => 'glp_get_col_lb',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ]
                 ],
    return_type => 'double'
  },
  { name => 'get_col_ub',
    function => 'glp_get_col_ub',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ]
                 ],
    return_type => 'double'
  },
  { name => 'get_obj_coef',
    function => 'glp_get_obj_coef',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'int32_t', 'j' ]
                 ],
    return_type => 'double'
  },
  { name => 'get_num_nz',
    function => 'glp_get_num_nz',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'int32_t'
  },
#  { name => 'get_mat_row',
#    function => 'glp_get_mat_row',
#    arguments => [ [ 'glp_prob*', 'd->prob' ],
#                   [ 'int32_t', 'i' ],
#                   [ 'int*', 'ind' ],
#                   [ 'double*', 'val' ]
#    return_type => some combination of ind and val ...
#  },
#  { name => 'get_mat_col',
#    function => 'glp_get_mat_col',
#    arguments => [ [ 'glp_prob*', 'd->prob' ],
#                   [ 'int32_t', 'j' ],
#                   [ 'int*', 'ind' ],
#                   [ 'double*', 'val' ]
#    return_type => some combination of ind and val ...
#  },

  # glp_create_index skipped ...

  { name => 'find_row',
    function => 'glp_find_row',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'name' ] 
                 ],
    return_type => 'int32_t'
  },
  { name => 'find_col',
    function => 'glp_find_col',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'name' ] 
                 ],
    return_type => 'int32_t'
  },

  # glp_delete_index skipped ...

  { name => 'set_rii',
    function => 'glp_set_rii',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ],
                   [ 'double', 'rii' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_sjj',
    function => 'glp_set_sjj',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ],
                   [ 'double', 'sjj' ]
                 ],
    return_type => 'void'
  },
  { name => 'get_rii',
    function => 'glp_get_rii',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ],
                 ],
    return_type => 'double'
  },
  { name => 'get_sjj',
    function => 'glp_get_sjj',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ],
                 ],
    return_type => 'double'
  },
  { name => 'scale_prob',
    function => 'glp_scale_prob',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'enum', 
                       'scaleflags', 
                       [ 'glp_sf_gm', 
                         'glp_sf_eq', 
                         'glp_sf_2n', 
                         'glp_sf_skip',
                         'glp_sf_auto' ]
                     ],
                     'flags'
                   ],
                 ],
    return_type => 'void'
  },
  { name => 'unscale_prob',
    function => 'glp_unscale_prob',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'void'
  },
  { name => 'set_row_stat',
    function => 'glp_set_row_stat',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ],
                   [ [ 'enum', 
                       'status', 
                       [ 'glp_bs', 'glp_nl', 'glp_nu', 'glp_nf', 'glp_ns' ]
                     ],
                     'stat' ]
                 ],
    return_type => 'void'
  },
  { name => 'set_col_stat',
    function => 'glp_set_col_stat',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ],
                   [ [ 'enum', 
                       'status', 
                       [ 'glp_bs', 'glp_nl', 'glp_nu', 'glp_nf', 'glp_ns' ]
                     ],
                     'stat' ]
                 ],
    return_type => 'void'
  },
  { name => 'std_basis',
    function => 'glp_std_basis',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'void'
  },
  { name => 'adv_basis',
    function => 'glp_adv_basis',
    arguments => [ [ 'glp_prob*', 'd->prob' ], 
                   [ 'constant', '0' ] ],
    return_type => 'void'
  },
  { name => 'cpx_basis',
    function => 'glp_cpx_basis',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'void'
  },
  { name => 'simplex',
    function => 'glp_simplex',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'struct',
                       'glp_smcp',
                       [ 
                         [
                           [ 'optional',
                             [ 'enum',
                               'msglevel',
                               [ 'glp_msg_off', 
                                 'glp_msg_err',
                                 'glp_msg_on',
                                 'glp_msg_all'
                               ]
                             ],
                             'GLP_MSG_ALL'
                           ],
                           'msg_lev'
                         ],
                         [
                           [ 'optional',
                             [ 'enum',
                               'simplexmethod',
                               [ 'glp_primal', 'glp_dual', 'glp_dualp' ]
                             ],
                             'GLP_PRIMAL'
                           ],
                           'meth'
                         ],
                         [
                           [ 'optional',
                             [ 'enum', 
                               'simplexpricing', 
                               [ 'glp_pt_std',  'glp_pt_pse' ]
                             ],
                             'GLP_PT_PSE'
                           ],
                           'pricing'
                         ],
                         [ 
                           [ 'optional',
                             [ 'enum',
                               'simplexratiotest',
                               [ 'glp_rt_std', 'glp_rt_har' ]
                             ],
                             'GLP_RT_HAR'
                           ],
                           'r_test'
                         ],
                         [ [ 'optional', 'double', '1e-7' ], 'tol_bnd' ],
                         [ [ 'optional', 'double', '1e-7' ], 'tol_dj' ],
                         [ [ 'optional', 'double', '1e-10' ], 'tol_piv' ],
                         [ [ 'optional', 'double', '-DBL_MAX' ], 'obj_ll' ],
                         [ [ 'optional', 'double', '+DBL_MAX' ], 'obj_ul' ],
                         [ [ 'optional', 'int32_t', 'INT_MAX' ], 'it_lim' ],
                         [ [ 'optional', 'int32_t', 'INT_MAX' ], 'tm_lim' ],
                         [ [ 'optional', 'int32_t', '200' ], 'out_frq' ],
                         [ [ 'optional', 'int32_t', '0' ], 'out_dly' ],
                         [ [ 'optional',
                             [ 'enum', 'presolve', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'presolve'
                         ]
                       ],
                       'glp_init_smcp'
                     ],
                     'parm'
                   ]
                 ],
    return_type => [ 'asynchronous',
                     [ 'enum', 'simplexsolve', 
                       [ 'glp_success', 
                         'glp_ebadb',
                         'glp_esing',
                         'glp_econd',
                         'glp_ebound',
                         'glp_efail',
                         'glp_eobjll',
                         'glp_eobjul',
                         'glp_eitlim',
                         'glp_enopfs',
                         'glp_enodfs' 
                       ] 
                     ]
                   ]
  },
  { name => 'exact',
    function => 'glp_exact',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'struct',
                       'glp_smcp',
                       [ 
                         [
                           [ 'optional',
                             [ 'enum',
                               'msglevel',
                               [ 'glp_msg_off', 
                                 'glp_msg_err',
                                 'glp_msg_on',
                                 'glp_msg_all'
                               ]
                             ],
                             'GLP_MSG_ALL'
                           ],
                           'msg_lev'
                         ],
                         [ [ 'optional', 'int32_t', 'INT_MAX' ], 'it_lim' ],
                         [ [ 'optional', 'int32_t', 'INT_MAX' ], 'tm_lim' ],
                       ],
                       'glp_init_smcp'
                     ],
                     'parm'
                   ]
                 ],
    return_type => [ 'asynchronous',
                     [ 'enum', 'exactsolve', 
                       [ 'glp_success', 
                         'glp_ebadb',
                         'glp_esing',
                         'glp_ebound',
                         'glp_efail',
                         'glp_eitlim',
                         'glp_etmlim'
                       ] 
                     ]
                   ]
  },
  # glp_init_smcp skipped
  { name => 'get_status',
    function => 'glp_get_status',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => [ 'enum', 
                     'basicsolstatus',
                     [ 'glp_opt',
                       'glp_feas',
                       'glp_infeas',
                       'glp_nofeas',
                       'glp_unbnd',
                       'glp_undef' ]
                   ]
  },
  { name => 'get_prim_stat',
    function => 'glp_get_prim_stat',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => [ 'enum', 
                     'basicsolpdstat',
                     [ 'glp_undef',
                       'glp_feas',
                       'glp_infeas',
                       'glp_nofeas'
                     ]
                   ]
  },
  { name => 'get_dual_stat',
    function => 'glp_get_dual_stat',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => [ 'enum', 
                     'basicsolpdstat',
                     [ 'glp_undef',
                       'glp_feas',
                       'glp_infeas',
                       'glp_nofeas'
                     ]
                   ]
  },
  { name => 'get_obj_val',
    function => 'glp_get_obj_val',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'double'
  },
  { name => 'get_row_stat',
    function => 'glp_get_row_stat',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ] 
                 ],
    return_type => [ 'enum',
                     'rowcolstatus',
                     [ 'glp_bs',
                       'glp_nl',
                       'glp_nu',
                       'glp_nf',
                       'glp_ns'
                     ]
                   ]
  },
  { name => 'get_row_prim',
    function => 'glp_get_row_prim',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ] 
                 ],
    return_type => 'double'
  },
  { name => 'get_row_dual',
    function => 'glp_get_row_dual',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ] 
                 ],
    return_type => 'double'
  },
  { name => 'get_col_stat',
    function => 'glp_get_col_stat',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ] 
                 ],
    return_type => [ 'enum',
                     'rowcolstatus',
                     [ 'glp_bs',
                       'glp_nl',
                       'glp_nu',
                       'glp_nf',
                       'glp_ns'
                     ]
                   ]
  },
  { name => 'get_col_prim',
    function => 'glp_get_col_prim',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ] 
                 ],
    return_type => 'double'
  },
  { name => 'get_col_dual',
    function => 'glp_get_col_dual',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ] 
                 ],
    return_type => 'double'
  },
  { name => 'get_unbnd_ray',
    function => 'glp_get_unbnd_ray',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'int32_t'
  },
  { name => 'interior',
    function => 'glp_interior',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'struct',
                       'glp_iptcp',
                       [ 
                         [
                           [ 'optional',
                             [ 'enum',
                               'msglevel',
                               [ 'glp_msg_off', 
                                 'glp_msg_err',
                                 'glp_msg_on',
                                 'glp_msg_all'
                               ]
                             ],
                             'GLP_MSG_ALL'
                           ],
                           'msg_lev'
                         ],
                         [ 
                           [ 'optional',
                             [ 'enum',
                               'ordalg',
                               [ 'glp_ord_none',
                                 'glp_ord_qmd',
                                 'glp_ord_amd',
                                 'glp_ord_symamd'
                               ]
                             ],
                             'GLP_ORD_AMD'
                           ],
                           'ord_alg'
                         ]
                       ],
                       'glp_init_iptcp'
                     ],
                     'parm'
                   ]
                 ],
    return_type => [ 'asynchronous',
                     [ 'enum', 'interiorsolve', 
                       [ 'glp_success', 
                         'glp_efail',
                         'glp_enocvg',
                         'glp_eitlim',
                         'glp_einstab' 
                       ]
                     ]
                   ]
  },
  { name => 'ipt_status',
    function => 'glp_ipt_status',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => [ 'enum',
                     'iptstatus',
                     [ 'glp_undef', 'glp_opt', 'glp_infeas', 'glp_nofeas' ]
                   ]
  },
  { name => 'ipt_obj_val',
    function => 'glp_ipt_obj_val',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'double'
  },
  { name => 'ipt_row_prim',
    function => 'glp_ipt_row_prim',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ] 
                 ],
    return_type => 'double'
  },
  { name => 'ipt_row_dual',
    function => 'glp_ipt_row_dual',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ] 
                 ],
    return_type => 'double'
  },
  { name => 'ipt_col_prim',
    function => 'glp_ipt_col_prim',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ] 
                 ],
    return_type => 'double'
  },
  { name => 'ipt_col_dual',
    function => 'glp_ipt_col_dual',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ] 
                 ],
    return_type => 'double'
  },
  { name => 'set_col_kind',
    function => 'glp_set_col_kind',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ],
                   [ [ 'enum', 'varkind', [ 'glp_cv', 'glp_iv', 'glp_bv' ] ],
                     'kind'
                   ]
                 ],
    return_type => 'void'
  },
  { name => 'get_col_kind',
    function => 'glp_get_col_kind',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ]
                 ],
    return_type => [ 'enum', 'varkind', [ 'glp_cv', 'glp_iv', 'glp_bv' ] ],
  },
  { name => 'get_num_int',
    function => 'glp_get_num_int',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'int32_t'
  },
  { name => 'get_num_bin',
    function => 'glp_get_num_bin',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'int32_t'
  },
  { name => 'intopt',
    function => 'glp_intopt',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'struct',
                       'glp_iocp',
                       [ 
                         [
                           [ 'optional',
                             [ 'enum',
                               'msglevel',
                               [ 'glp_msg_off', 
                                 'glp_msg_err',
                                 'glp_msg_on',
                                 'glp_msg_all'
                               ]
                             ],
                             'GLP_MSG_ALL'
                           ],
                           'msg_lev'
                         ],
                         [
                           [ 'optional',
                             [ 'enum',
                               'brtech',
                               [ 'glp_br_ffv',
                                 'glp_br_lfv',
                                 'glp_br_mfv',
                                 'glp_br_dth'
                               ]
                             ],
                             'GLP_BR_DTH'
                           ],
                           'br_tech'
                         ],
                         [
                           [ 'optional',
                             [ 'enum',
                               'bttech',
                               [ 'glp_bt_dfs',
                                 'glp_bt_bfs',
                                 'glp_bt_blb',
                                 'glp_bt_bph'
                               ]
                             ],
                             'GLP_BT_BLB'
                           ],
                           'bt_tech'
                         ],
                         [
                           [ 'optional',
                             [ 'enum',
                               'pptech',
                               [ 'glp_pp_none',
                                 'glp_pp_root',
                                 'glp_pp_all',
                               ]
                             ],
                             'GLP_PP_ALL'
                           ],
                           'pp_tech'
                         ],
                         [
                           [ 'optional',
                             [ 'enum', 'fpheur', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'fp_heur'
                         ],
                         [
                           [ 'optional',
                             [ 'enum', 'gmicuts', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'gmi_cuts'
                         ],
                         [
                           [ 'optional',
                             [ 'enum', 'mircuts', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'mir_cuts'
                         ],
                         [
                           [ 'optional',
                             [ 'enum', 'covcuts', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'cov_cuts'
                         ],
                         [
                           [ 'optional',
                             [ 'enum', 'clqcuts', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'clq_cuts'
                         ],
                         [ [ 'optional', 'double', '1e-5' ], 'tol_int' ],
                         [ [ 'optional', 'double', '1e-7' ], 'tol_obj' ],
                         [ [ 'optional', 'double', '0.0' ], 'mip_gap' ],
                         [ [ 'optional', 'int32_t', 'INT_MAX' ], 'tm_lim' ],
                         [ [ 'optional', 'int32_t', '5000' ], 'out_frq' ],
                         [ [ 'optional', 'int32_t', '10000' ], 'out_dly' ],
                         # skipping cb_func, cb_info, cb_size
                         [ [ 'optional',
                             [ 'enum', 'presolve', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'presolve'
                         ],
                         [ [ 'optional',
                             [ 'enum', 'binarize', [ 'glp_off', 'glp_on' ] ],
                             'GLP_OFF'
                           ],
                           'binarize'
                         ]
                       ],
                       'glp_init_iocp'
                     ],
                     'parm'
                   ]
                 ],
    return_type => [ 'asynchronous',
                     [ 'enum', 'intsolve', 
                       [ 'glp_success', 
                         'glp_ebound',
                         'glp_eroot',
                         'glp_enopfs',
                         'glp_enodfs',
                         'glp_efail',
                         'glp_emipgap',
                         'glp_etmlim',
                         'glp_estop',
                       ]
                     ]
                   ]
  },
  { name => 'mip_status',
    function => 'glp_mip_status',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => [ 'enum', 
                     'mipstatus', 
                     [ 'glp_undef', 'glp_opt', 'glp_feas', 'glp_nofeas' ]
                   ]
  },
  { name => 'mip_obj_val',
    function => 'glp_mip_obj_val',
    arguments => [ [ 'glp_prob*', 'd->prob' ] ],
    return_type => 'double'
  },
  { name => 'mip_row_val',
    function => 'glp_mip_row_val',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'i' ] 
                 ],
    return_type => 'double'
  },
  { name => 'mip_col_val',
    function => 'glp_mip_col_val',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'int32_t', 'j' ] 
                 ],
    return_type => 'double'
  },
  # lpx_check_kkt skipped
  { name => 'read_mps',
    function => 'glp_read_mps',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'enum', 
                       'mpsformat', 
                       [ 'glp_mps_deck', 'glp_mps_file' ] 
                     ],
                     'fmt'
                   ],
                   [ 'constant', 'NULL' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'write_mps',
    function => 'glp_write_mps',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ [ 'enum', 
                       'mpsformat', 
                       [ 'glp_mps_deck', 'glp_mps_file' ] 
                     ],
                     'fmt'
                   ],
                   [ 'constant', 'NULL' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'read_lp',
    function => 'glp_read_lp',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'constant', 'NULL' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'write_lp',
    function => 'glp_write_lp',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'constant', 'NULL' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  # mathprog model routines skipped ...
  { name => 'print_sol',
    function => 'glp_print_sol',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'read_sol',
    function => 'glp_read_sol',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'write_sol',
    function => 'glp_write_sol',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'print_sens_bnds',
    function => 'lpx_print_sens_bnds',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'print_ipt',
    function => 'glp_print_ipt',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'read_ipt',
    function => 'glp_read_ipt',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'write_ipt',
    function => 'glp_write_ipt',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'print_mip',
    function => 'glp_print_mip',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'read_mip',
    function => 'glp_read_mip',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  { name => 'write_mip',
    function => 'glp_write_mip',
    arguments => [ [ 'glp_prob*', 'd->prob' ],
                   [ 'const char*', 'fname' ]
                 ],
    return_type => 'int32_t'
  },
  # advanced api routines skipped ...
  # branch-and-cut api routines skipped ...
  # graph and network api routines skipped ...
  # miscellaneous api routines skipped ...
);
