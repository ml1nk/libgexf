#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
TMPDIR=build/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
OUTPUT_PATH=dist/Debug/${PLATFORM}/libgexf.so
OUTPUT_BASENAME=libgexf.so
PACKAGE_TOP_DIR=libgexf-src.0.1.0/

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p dist/Debug/${PLATFORM}/package
rm -rf ${TMPDIR}
mkdir -p ${TMPDIR}

# Copy files and create directories and links
cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding
copyFileToTmpDir "binding/build.sh" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/build.sh" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/build.sh" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/build.sh" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Win32.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Win32.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/AuthorTests.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/AuthorTests.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Compiler.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Compiler.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/WriteAll.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/WriteAll.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Fetch.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Fetch.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Can.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Can.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Include.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Include.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Makefile.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Makefile.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Base.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Base.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module/Install
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install/Metadata.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install/Metadata.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Module
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Module/Install.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Module/Install.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/inc/Test
copyFileToTmpDir "binding/perl/Graph-LibGEXF/inc/Test/More.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/inc/Test/More.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/pmdoc" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/pmdoc" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/README" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/README" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/Changes" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/Changes" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/xt
copyFileToTmpDir "binding/perl/Graph-LibGEXF/xt/91_pod.t" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/xt/91_pod.t" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/xt
copyFileToTmpDir "binding/perl/Graph-LibGEXF/xt/90_perlcritic.t" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/xt/90_perlcritic.t" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/xt
copyFileToTmpDir "binding/perl/Graph-LibGEXF/xt/perlcriticrc" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/xt/perlcriticrc" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/MANIFEST.SKIP" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/MANIFEST.SKIP" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/libgexf.i" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/libgexf.i" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/Makefile.PL" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/Makefile.PL" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/Makefile.old" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/Makefile.old" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/libgexf_wrap.o" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/libgexf_wrap.o" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/t
copyFileToTmpDir "binding/perl/Graph-LibGEXF/t/00_compile.t" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/t/00_compile.t" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/Makefile" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/Makefile" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF/lib/Graph
copyFileToTmpDir "binding/perl/Graph-LibGEXF/lib/Graph/LibGEXF.pm" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/lib/Graph/LibGEXF.pm" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/perl/Graph-LibGEXF
copyFileToTmpDir "binding/perl/Graph-LibGEXF/META.yml" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/perl/Graph-LibGEXF/META.yml" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/build.sh" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/build.sh" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/libgexf_wrap.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/libgexf_wrap.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/test.sh" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/test.sh" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/Manifest.txt" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/Manifest.txt" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/runme.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/runme.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/SWIGTYPE_p_std__setT_unsigned_int_t.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/SWIGTYPE_p_std__setT_unsigned_int_t.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/libgexfJNI.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/libgexfJNI.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/GEXF.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/GEXF.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/UndirectedGraph.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/UndirectedGraph.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/MessageExceptionBuilder.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/MessageExceptionBuilder.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/Graph.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/Graph.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/SWIGTYPE_p_std__string.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/SWIGTYPE_p_std__string.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/DirectedGraph.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/DirectedGraph.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/WriteLockException.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/WriteLockException.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/ReadLockException.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/ReadLockException.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java/org/gephi/libgexf
copyFileToTmpDir "binding/java/org/gephi/libgexf/libgexf.java" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/org/gephi/libgexf/libgexf.java" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/libgexf.i" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/libgexf.i" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/java
copyFileToTmpDir "binding/java/libgexf.jar" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/java/libgexf.jar" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/build.sh" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/build.sh" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/test.py" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/test.py" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/README" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/README" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/libgexf_wrap.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/libgexf_wrap.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/libgexf.pyc" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/libgexf.pyc" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/libgexf.i" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/libgexf.i" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/setup.py" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/setup.py" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/clean.sh" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/clean.sh" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/binding/python
copyFileToTmpDir "binding/python/libgexf.py" "${TMPDIR}/${PACKAGE_TOP_DIR}binding/python/libgexf.py" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/abstractiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/abstractiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/abstractparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/abstractparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/attributeiter.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/attributeiter.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/attributeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/attributeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/attvalueiter.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/attvalueiter.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/attvalueiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/attvalueiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "changelog.Debian.gz" "${TMPDIR}/${PACKAGE_TOP_DIR}changelog.Debian.gz" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "changelog.gz" "${TMPDIR}/${PACKAGE_TOP_DIR}changelog.gz" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/conv.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/conv.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/conv.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/conv.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "copyright" "${TMPDIR}/${PACKAGE_TOP_DIR}copyright" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/data.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/data.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/data.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/data.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/directedgraph.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/directedgraph.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/directedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/directedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "doxygen.conf" "${TMPDIR}/${PACKAGE_TOP_DIR}doxygen.conf" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/edgeiter.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/edgeiter.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/edgeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/edgeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/exceptions.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/exceptions.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/filereader.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/filereader.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/filereader.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/filereader.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/filewriter.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/filewriter.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/filewriter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/filewriter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/gexf.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/gexf.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/gexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/gexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/gexfparser.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/gexfparser.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/gexfparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/gexfparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/graph.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/graph.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/graph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/graph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/legacyparser.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/legacyparser.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/legacyparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/legacyparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/libgexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/libgexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "Makefile" "${TMPDIR}/${PACKAGE_TOP_DIR}Makefile" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/metadata.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/metadata.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/metadata.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/metadata.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/nodeiter.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/nodeiter.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/nodeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/nodeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "README" "${TMPDIR}/${PACKAGE_TOP_DIR}README" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "README_SWIG" "${TMPDIR}/${PACKAGE_TOP_DIR}README_SWIG" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "TODO" "${TMPDIR}/${PACKAGE_TOP_DIR}TODO" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/typedefs.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/typedefs.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/undirectedgraph.cpp" "${TMPDIR}/${PACKAGE_TOP_DIR}src/undirectedgraph.cpp" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/src
copyFileToTmpDir "src/undirectedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/undirectedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir "doc/latex/refman.pdf" "${TMPDIR}/${PACKAGE_TOP_DIR}refman.pdf" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Package-Debug.bash" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Package-Debug.bash" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/project.xml" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/project.xml" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Package-Release-deb.bash" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Package-Release-deb.bash" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Makefile-Release.mk" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Makefile-Release.mk" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/project.properties" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/project.properties" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/configurations.xml" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/configurations.xml" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Makefile-Release-deb.mk" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Makefile-Release-deb.mk" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Makefile-Debug.mk" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Makefile-Debug.mk" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Makefile-impl.mk" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Makefile-impl.mk" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject/private
copyFileToTmpDir "nbproject/private/private.xml" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/private/private.xml" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject/private
copyFileToTmpDir "nbproject/private/configurations.xml" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/private/configurations.xml" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject/private
copyFileToTmpDir "nbproject/private/private.properties" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/private/private.properties" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0/nbproject
copyFileToTmpDir "nbproject/Package-Release.bash" "${TMPDIR}/${PACKAGE_TOP_DIR}nbproject/Package-Release.bash" 0755

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf-src.0.1.0
copyFileToTmpDir ".dep.inc" "${TMPDIR}/${PACKAGE_TOP_DIR}.dep.inc" 0644


# Generate tar file
cd "${TOP}"
rm -f dist/Debug/${PLATFORM}/package/libgexf-src.0.1.0.tar
cd ${TMPDIR}
tar -vcf ../../../../dist/Debug/${PLATFORM}/package/libgexf-src.0.1.0.tar *
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}
