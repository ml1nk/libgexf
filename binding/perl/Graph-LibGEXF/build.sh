#!/bin/bash

# clean
rm -Rf build
rm -f MANIFEST
rm -f libgexf_wrap.cpp
rm -f pm_to_blib
rm -f _libgexf.so
#rm *.o # do not delete

# build
swig -c++ -perl -o libgexf_wrap.cpp libgexf.i
#gcc -fPIC -c libgexf_wrap.cpp ../../../graph.cpp ../../../gexf.cpp -I/usr/lib/perl/5.10.0/CORE
g++ -c -fpic libgexf_wrap.cpp ../../../graph.cpp ../../../gexf.cpp -D_REENTRANT -D_GNU_SOURCE -DDEBIAN -fno-strict-aliasing -pipe -isystem /usr/local/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/lib/perl/5.10.0/CORE
g++ -shared libgexf_wrap.o graph.o gexf.o -o _libgexf.so

