libelinalinearize = library('elinalinearize',
  sources: [
    'elina_generic.c',
    'elina_scalar_arith.c',
    'elina_interval_arith.c',
    'elina_coeff_arith.c',
    'elina_linexpr0_arith.c',
    'elina_linearize.c',
    'elina_linearize_texpr.c'
  ],
  dependencies: dependencies + [libelinaux_dep],
  c_args: c_args,
  install: true
)

libelinalinearize_dep = declare_dependency(
  link_with: libelinalinearize,
  dependencies: dependencies + [libelinaux_dep],
  include_directories: [include_directories('.')]
)
