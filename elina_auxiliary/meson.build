libelinaux = library('elinaux',
  sources: [
    'elina_scalar.c',
    'elina_interval.c',
    'elina_coeff.c',
    'elina_dimension.c',
    'elina_linexpr0.c',
    'elina_lincons0.c',
    'elina_manager.c',
    'elina_abstract0.c',
    'elina_texpr0.c',
    'elina_tcons0.c'
  ],
  dependencies: dependencies,
  c_args: c_args,
  install: true
)

libelinaux_dep = declare_dependency(
  link_with: libelinaux,
  dependencies: dependencies,
  include_directories: [include_directories('.')]
)

# tests
test('coeff',
  executable('elina_coeff_test',
    'coeff_test.c',
    dependencies: [libelinaux_dep],
    install: false
  )
)
