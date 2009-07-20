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
  'stdc++', # IMPORTANT: linker to lib STD
  'xml2'
  ;

# if object files are not in the same dir as source files
makemaker_args
  DEFINE => '-o $*$(OBJ_EXT) -c';

cc_inc_paths
  '.';

cc_files
    #io::input
    '../../../filereader.o',
    '../../../gexfparser.o',
    '../../../legacyparser.o',
    
    #io::output
    '../../../filewriter.o',
    
    #io::utils
    '../../../conv.o',
    
    #db::topo
    '../../../graph.o',
    '../../../directedgraph.o',
    '../../../undirectedgraph.o',
    '../../../nodeiter.o',
    '../../../edgeiter.o',
    
    #db::data
    '../../../data.o',
    '../../../metadata.o',
    '../../../attributeiter.o',
    '../../../attvalueiter.o',
    
    #main
    '../../../gexf.o',

    # chemin du wrapper généré automatiquement par SWIG (ce wrapper doit déjà exister donc)
    'libgexf_wrap.o';

can_cc or die 'This module requires C++ compiler.';




WriteAll;

