#!/bin/bash

# total clean
rm -Rf build
rm -f libgexf_wrap.cpp
rm *.o

# build
swig -c++ -python -o libgexf_wrap.cpp libgexf.i
python setup.py build

./clean.sh

