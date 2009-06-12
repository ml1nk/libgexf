use inc::Module::Install;
name 'Graph-LibGEXF';
all_from 'lib/Graph/LibGEXF.pm';

# requires '';

tests 't/*.t';
author_tests 'xt';

build_requires 'Test::More';
use_test_base;
auto_include;



cc_lib_links
  'm',
  #'z', # zlib
  ;

#makemaker_args
#  DEFINE => '-o $*$(OBJ_EXT) -c';

cc_inc_paths
  '.';

cc_files
  'graph.o',
  'directedgraph.o',
  'undirectedgraph.o',
  'gexf.o',
  'libgexf_wrap.o';

can_cc or die 'This module requires C++ compiler.';




WriteAll;

