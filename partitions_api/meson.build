libelinapartitions = library('elinapartitions',
  sources: [
    'comp_list.c',
    'array_comp_list.c',
    'intersection.c',
    'union.c',
    'extract.c'
  ],
  dependencies: dependencies,
  c_args: c_args,
  install: true
)

libelinapartitions_dep = declare_dependency(
  link_with: [libelinapartitions],
  dependencies: dependencies,
  include_directories: [include_directories('.')]
)
