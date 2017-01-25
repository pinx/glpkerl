# Introduction

This project provides an Erlang interface to GLPK.

You probably know what [GLPK](http://www.gnu.org/software/glpk/)  is, otherwise, you wouldn't have much interest in the project.

## Hello World!

In case you don't want to read all the mumbo jumbo, here's an example first solving
```
  min x
  0 <= x <= 100
```
and then
```
  max x
  0 <= x <= 100
```


```
% erl
Erlang (BEAM) emulator version 5.6.5 [source] [async-threads:0] [kernel-poll:fal
se]

Eshell V5.6.5  (abort with ^G)
1> glpkerl:start ().
ok
2> { ok, Lp } = glpkerl:new ().
{ok,{glpk,#Port<0.721>,false,32,64}}
3> 1 = glpkerl:add_rows (Lp, 1).
1
4> ok = glpkerl:set_row_bnds (Lp, 1, glp_up, 0, 100).
ok
5> 1 = glpkerl:add_cols (Lp, 1).
1
6> ok = glpkerl:set_col_bnds (Lp, 1, glp_lo, 0, 0).
ok
7> ok = glpkerl:set_obj_coef (Lp, 1, 1.0).
ok
8> ok = glpkerl:load_matrix (Lp, 1, [ 1 ], [ 1 ], [ 1 ]).
ok
9> glp_success = glpkerl:simplex (Lp, []).
*     0: obj =   0.000000000e+00  infeas =  0.000e+00 (0)
                                                         OPTIMAL SOLUTION FOUND
                                                                               g
lp_success
10> ok = glpkerl:set_obj_dir (Lp, glp_max).
ok
11> glp_success = glpkerl:simplex (Lp, []).
*     0: obj =   0.000000000e+00  infeas =  0.000e+00 (0)
                                                         *     1: obj =   1.0000
00000e+02  infeas =  0.000e+00 (0)
                                  OPTIMAL SOLUTION FOUND
                                                        glp_success
12>
User switch command
 --> q
```

## Port vs. Linked-In

In Erlang you have the choice between a port (forked program communicating over a socketpair) or a linked-in driver (dynamically loaded library residing in Erlang VM's address space).

Generally linked-in drivers are dangerous because they can destabilize the VM, but are sometimes used because they offer lower latency.  Since solving a linear program is a very heavyweight operation, the latency of talking over a pipe is probably moot.  Furthermore, it's very easy to shut down a subprocess without blocking the Erlang VM, whereas a linked-in driver with a thread that is doing a long running computation can potentially block the Erlang VM if the port_close method is invoked during the long running computation (which could happen if the port owner dies after initiating a large linear program solve).

For these reasons the default mode of operation is port.  You can select linked-in driver when constructing a handle, but it's probably a bad idea.  (Really, the only reason it is there is because I have a way to convert a linked-in driver to a port, so I always write the linked-in driver first).

## Calling Conventions

Much of the software is this package is auto-generated, and therefore the interface is a near-literal translation of the C api, with the following conventions:


### Return Types

Any method can return { error, Reason }, which indicates an error not associated with a GLPK return value.  except for the port dying, this generally means an internal_error in the driver (i.e., software defect by me!).

In addition each method can return a value which depends upon the return value of the associated glpk method.  This value is *never* an Erlang tuple so you can distinguish it from the error case.

|| C return type || Erlang type ||
|| void || 'ok' ||
|| int || integer () ||
|| enumeration || 'lowercase_first_enum_val' | 'lowercase_second_enum_val' ... ||
|| double || float () ||

With respect to enumerations, basically an enum on the C side is associated with a sum of atoms type on the Erlang side, with lowercasing for convenience.  So something like the return type for `glp_get_prim_stat`, which is (essentially) declared as
```
enum
{
GLP_UNDEF,
GLP_FEAS,
GLP_INFEAS,
GLP_NOFEAS
}
```
would be the Erlang type
```
'glp_undef' | 'glp_feas' | 'glp_infeas' | 'glp_nofeas'
```
Also some methods, e.g. `glp_simplex`, return 0 to indicate success but otherwise an enumeration.  I define this as 'glp_success'.

The interface file (`glpkerl.erl`) generates proper EDoc and dialyzer type signatures so hopefully it is clear what is going on.

### Argument Types

For each mapped GLPK function, the argument types are mapped to Erlang as follows:
```
|| C argument type || Erlang type ||
|| glp_prob* || implicit: contained in the glpkerl instance ||
|| int || integer () ||
|| double || number () ||
|| const int* || list (integer ()) ||
|| const double* || list (number ()) ||
|| enumeration || 'lowercase_first_enum_val' | 'lowercase_second_enum_val' ... ||
|| const struct X* || proplist () ||
```
With respect to enumerations, basically an enum on the C side is associated with a sum of atoms type on the Erlang side, with lowercasing for convenience.  So for instance the msg_level parameter would be ( 'glp_msg_off' | 'glp_msg_err' | 'glp_msg_on' | 'glp_msg_all' ).

With respect to (pointers to) structures, I map these to proplists where the keys are atoms corresponding to the member names of the structure.  So a call to `glp_simplex` might look like
```
  { ok, Lp } = glpkerl:new (),
  ...
  glp_success = glpkerl:simplex (Lp, [ { msg_level, 'glp_msg_off' } ]),
```

# Installation

## Introduction

Do NOT attempt to build from a checkout from the source code repository: that is for wizards only. Instead, grab one of the released source tarballs from the [downloads](http://code.google.com/p/glpkerl/downloads) tab.

This page will assist you in installing glpkerl.[[#2 2]]

Prerequisites:
  1. gnu make
  1. working glpk 4.38 installation
     * debian: aptitude install libglpk-dev=4.38-1
     * others: ??? please let me know what worked
  1. working erlang installation.
     * debian: aptitude install erlang-dev
     * os/x (with [http://www.finkproject.org/ fink]): apt-get install erlang-otp
     * freebsd: pkg_add -r erlang
     * others: ??? please let me know what worked

Go to the [downloads section](http://code.google.com/p/glpkerl/downloads/list?can=2&q=*.tar.gz&colspec=Filename+Summary+Uploaded+Size+DownloadCount) and grab the latest `.tar.gz` files: one C driver tarball, and one Erlang tarball.

## C driver

```
# tar -zxf glpkerldrv-4.38.0.tar.gz
# cd glpkerldrv-4.38.0
# ./configure --prefix /usr/local && make && make -s check
...
```
The default prefix is `/usr` so if you are ok with that you can omit the prefix argument.

If you get compile warnings that are being interpreted as errors, drop me a line about it because I'd like to fix it, and then workaround it with the `--disable-hardcore` flag to configure:
```
# ./configure --prefix /usr/local --disable-hardcore && make && make -s check
```

Now you can `make install`, or if you have another way of managing stuff on your system, you can `make DESTDIR=/whatever install` and then manipulate the contents of `/whatever`.

### Erlang source code

You'll need the C driver built and installed first.

```
# tar -zxf glpkerl-4.38.0.tar.gz
# cd glpkerl-4.38.0
# ./configure --prefix /usr/local && make && make -s check
```
Hopefully what you see[[#1 1]] is something like
```
PASS: module-testglpkerl
==================
All 1 tests passed
==================
```

There are a couple ways this could go wrong.  

One way this could go wrong is because the Erlang build process cannot find the driver specification.  The Erlang source code (and the linked-in driver) are generated automatically from a specification `glpkerldrvspec.pm` and the Erlang build process uses pkg-config to find the installed specification.  Thus, if the .pc file for the C driver is not in the path for pkg-config, the build process will fail.  Modifying the environment variable `PKG_CONFIG_PATH` might assist with this problem.

You could also inspect the test output, which for `test-FOO` is in `tests/test-FOO.out`; perhaps it is informative.

Now you can `make install`, or if you have another way of managing stuff on your system, you can `make DESTDIR=/whatever install` and then manipulate the contents of `/whatever`.

# Footnotes

== 1 ==
If you see something like:
```
fw requires GNU make to build, you are using bsd make
*** Error code 1

Stop.
```
Then you are using bsd make which will not work.  Try again with gnu make, e.g.,
```
./configure --prefix /usr/local && gmake && gmake -s check
```

== 2 ==

Downloadable source tarballs use automake to build. A source code checkout of the repository uses [fwtemplates](http://code.google.com/p/framewerk) to build, and if you don't know what that is, you probably want to stick with the tarballs.
