#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
TMPDIR=build/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
OUTPUT_PATH=dist/Release/${PLATFORM}/libgexf.so
OUTPUT_BASENAME=libgexf.so
PACKAGE_TOP_DIR=libgexf.so.0.1.0/

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
mkdir -p dist/Release/${PLATFORM}/package
rm -rf ${TMPDIR}
mkdir -p ${TMPDIR}

# Copy files and create directories and links
cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/lib
copyFileToTmpDir "${OUTPUT_PATH}" "${TMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/abstractiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/abstractiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/abstractparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/abstractparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/attributeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/attributeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/attvalueiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/attvalueiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0
copyFileToTmpDir "changelog.gz" "${TMPDIR}/${PACKAGE_TOP_DIR}changelog.gz" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/conv.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/conv.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/data.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/data.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/directedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/directedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/edgeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/edgeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/exceptions.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/exceptions.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/filereader.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/filereader.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/filewriter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/filewriter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/gexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/gexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/gexfparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/gexfparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/graph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/graph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/legacyparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/legacyparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/libgexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/libgexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/metadata.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/metadata.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/nodeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/nodeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "README" "${TMPDIR}/${PACKAGE_TOP_DIR}src/README" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "TODO" "${TMPDIR}/${PACKAGE_TOP_DIR}src/TODO" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/typedefs.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/typedefs.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/src
copyFileToTmpDir "src/undirectedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}src/undirectedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/t
copyFileToTmpDir "t/simple.gexf" "${TMPDIR}/${PACKAGE_TOP_DIR}t/simple.gexf" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.0/t
copyFileToTmpDir "t/attributes.gexf" "${TMPDIR}/${PACKAGE_TOP_DIR}t/attributes.gexf" 0644


# Generate tar file
cd "${TOP}"
rm -f dist/Release/${PLATFORM}/package/libgexf.so.0.1.0.tar
cd ${TMPDIR}
tar -vcf ../../../../dist/Release/${PLATFORM}/package/libgexf.so.0.1.0.tar *
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}
