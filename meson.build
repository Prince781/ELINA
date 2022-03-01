project('ELINA', 'c',
        version: '2.1',
        default_options: ['c_std=c99', 'buildtype=debugoptimized', 'default_library=both'])

cc = meson.get_compiler('c')

pkg = import('pkgconfig')

c_args = cc.get_supported_arguments([
  '-Wcast-qual',
  '-Wswitch',
  '-Wall',
  '-Wextra',
  '-Wundef',
  '-Wcast-align',
  '-Wno-unused',
  '-U__STRICT_ANSI__',
  '-Werror-implicit-function-declaration',
  '-Wbad-function-cast',
  '-Wstrict-prototypes',
  '-Wno-strict-overflow',
  # architecture specific flags
  '-fno-tree-vectorize',
  '-m64',
  '-march=native',
  '-ffp-contract=off'
])

c_args += [
  '-DNDEBUG',
  '-D_GNU_SOURCE',
  '-DNUM_LONGLONGRAT',
  '-DNUM_DOUBLE',
  '-DTHRESHOLD=0.75',
  '-DTIMING'
]

# TODO: check for vector intrinsics

if get_option('has_vector')
  c_args += ['-DVECTOR']
endif

dependencies = [
  dependency('threads'),
  cc.find_library('gmp'),
  cc.find_library('mpfr'),
  cc.find_library('m', required: false)
]

subdir('elina_auxiliary')
subdir('elina_linearize')
subdir('partitions_api')
# TODO: other components
subdir('elina_oct')

pkg.generate(
  libraries: [libelinaux, libelinalinearize, libelinaoct],
  name: 'ELINA',
  filebase: 'elina',
  description: 'ETH Library for Numerical Analysis'
)

libelina_dep = declare_dependency(
  link_with: [libelinaux, libelinalinearize, libelinaoct],
  dependencies: dependencies + [libelinaux_dep, libelinalinearize_dep, libelinaoct_dep],
  include_directories: [include_directories('.')]
)

# for using this project as a subproject
meson.override_dependency('elina', libelina_dep)
