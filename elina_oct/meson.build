if not get_option('has_vector')
  libelinaoct_closure_sources = [
    'opt_oct_closure_comp_sparse.c',
    'opt_oct_incr_closure_comp_sparse.c',
    'opt_oct_closure_dense_scalar.c',
    'opt_oct_incr_closure_dense_scalar.c'
  ]
else
  libelinaoct_closure_sources = [
    'opt_oct_closure_comp_sparse.c',
    'opt_oct_incr_closure_comp_sparse.c',
    'opt_oct_closure_dense.c',
    'opt_oct_incr_closure_dense.c'
  ]
endif

libelinaoct = library('elinaoct',
  sources: [
    'opt_oct_nary.c',
    'opt_oct_resize.c',
    'opt_oct_predicate.c',
    'opt_oct_representation.c',
    'opt_oct_transfer.c',
    'opt_oct_hmat.c'
  ] + libelinaoct_closure_sources,
  dependencies: dependencies + [libelinalinearize_dep, libelinapartitions_dep],
  c_args: c_args,
  install: true
)

libelinaoct_dep = declare_dependency(
  link_with: [libelinaoct],
  dependencies: dependencies + [libelinalinearize_dep, libelinapartitions_dep],
  include_directories: [include_directories('.')]
)

# tests

test('oct',
  executable('elina_test_oct',
    'elina_test_oct.c',
    dependencies: [libelinaoct_dep],
    install: false
  ),
  args: ['10', '3']
)
