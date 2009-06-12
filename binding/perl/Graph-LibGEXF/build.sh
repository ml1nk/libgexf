#!/bin/bash
echo " ---------------------------------"
echo " |         Perl5 building        |"
echo " ---------------------------------"
echo ""
# clean
#rm -R build
#rm MANIFEST
#rm libgexf_wrap.cpp
#rm pm_to_blib
#rm _libgexf.so
#rm *.o # do not delete

echo "Generating interface files.."
swig -c++ -perl -o libgexf_wrap.cpp libgexf.i

echo "Compiling.."
#gcc -fPIC -c libgexf_wrap.cpp ../../../graph.cpp ../../../gexf.cpp -I/usr/lib/perl/5.10.0/CORE
g++ -c -fpic libgexf_wrap.cpp \
    ../../../graph.cpp \
    ../../../directedgraph.cpp \
    ../../../undirectedgraph.cpp \
    ../../../gexf.cpp \
    -D_REENTRANT -D_GNU_SOURCE -DDEBIAN -fno-strict-aliasing -pipe -isystem /usr/local/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 \
    -I/usr/lib/perl/5.10.0/CORE
g++ -shared libgexf_wrap.o graph.o gexf.o -o _libgexf.so

echo "Cleaning.."
rm libgexf_wrap.cpp

