#!/bin/bash
echo " ---------------------------------"
echo " |    Java (jdk6) building   |"
echo " ---------------------------------"
echo ""
echo "Generating interface files.."
swig -c++ -java -package org.gephi.libgexf -outdir org/gephi/libgexf -o libgexf_wrap.cpp libgexf.i

echo "Compiling.."
gcc -fPIC -c libgexf_wrap.cpp \
    ../../graph.cpp \
    ../../directedgraph.cpp \
    ../../undirectedgraph.cpp \
    ../../gexf.cpp \
    -I/usr/lib/jvm/java-6-sun-1.6.0.10/include -I/usr/lib/jvm/java-6-sun-1.6.0.10/include/linux
g++ -shared libgexf_wrap.o graph.o directedgraph.o undirectedgraph.o gexf.o -o libgexf.so

#echo "Creating JAR.."
#javac org/gephi/libgexf/*.java
#jar cfm libgexf.jar Manifest.txt org/gephi/libgexf/*.class
# TODO edit Manifest.txt Main-Class

echo "Cleaning.."
rm *.o
#rm libgexf_wrap.cpp
echo "Testing.."
javac runme.java
java runme #-verbose:jni

echo "Done!"

