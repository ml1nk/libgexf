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
PACKAGE_TOP_DIR=libgexf.so.0.1.2/

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
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/lib
copyFileToTmpDir "${OUTPUT_PATH}" "${TMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/abstractiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/abstractiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/abstractparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/abstractparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/attributeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/attributeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/attvalueiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/attvalueiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2
copyFileToTmpDir "changelog.gz" "${TMPDIR}/${PACKAGE_TOP_DIR}changelog.gz" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/conv.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/conv.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/data.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/data.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/directedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/directedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/edgeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/edgeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/exceptions.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/exceptions.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/filereader.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/filereader.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/filewriter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/filewriter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/gexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/gexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/gexfparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/gexfparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/graph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/graph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/legacyparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/legacyparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/libgexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/libgexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/metadata.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/metadata.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/nodeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/nodeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "README" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/README" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "TODO" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/TODO" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/typedefs.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/typedefs.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/libgexf
copyFileToTmpDir "libgexf/undirectedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}libgexf/undirectedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/t
copyFileToTmpDir "t/simple.gexf" "${TMPDIR}/${PACKAGE_TOP_DIR}t/simple.gexf" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}/libgexf.so.0.1.2/t
copyFileToTmpDir "t/attributes.gexf" "${TMPDIR}/${PACKAGE_TOP_DIR}t/attributes.gexf" 0644


# Generate tar file
cd "${TOP}"
rm -f dist/Release/${PLATFORM}/package/libgexf.so.0.1.2.tar
cd ${TMPDIR}
tar -vcf ../../../../dist/Release/${PLATFORM}/package/libgexf.so.0.1.2.tar *
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}
