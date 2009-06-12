#!/bin/bash
echo " ---------------------------------"
echo " |        Python building        |"
echo " ---------------------------------"
echo ""
# total clean
#rm -R build
#rm libgexf_wrap.cpp
#rm *.o

echo "Generating interface files.."
swig -c++ -python -o libgexf_wrap.cpp libgexf.i

echo "Compiling.."
python setup.py build

echo "Cleaning.."
./clean.sh

