#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release-deb
CND_DISTDIR=dist
TMPDIR=build/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
OUTPUT_PATH=dist/Release/${PLATFORM}/libgexf.so
OUTPUT_BASENAME=libgexf.so
PACKAGE_TOP_DIR=/usr/

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
makeDirectory ${TMPDIR}//usr/lib
copyFileToTmpDir "${OUTPUT_PATH}" "${TMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/abstractiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/abstractiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/abstractparser.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/abstractparser.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/attributeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/attributeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/attvalueiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/attvalueiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/data.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/data.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/directedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/directedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/edgeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/edgeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/exceptions.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/exceptions.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/filereader.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/filereader.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/filewriter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/filewriter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/gexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/gexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/graph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/graph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/libgexf.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/libgexf.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/metadata.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/metadata.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/nodeiter.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/nodeiter.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/typedefs.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/typedefs.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/include/libgexf
copyFileToTmpDir "libgexf/undirectedgraph.h" "${TMPDIR}/${PACKAGE_TOP_DIR}include/libgexf/undirectedgraph.h" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/share/doc/libgexf
copyFileToTmpDir "changelog.gz" "${TMPDIR}/${PACKAGE_TOP_DIR}share/doc/libgexf/changelog.gz" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/share/doc/libgexf
copyFileToTmpDir "changelog.Debian.gz" "${TMPDIR}/${PACKAGE_TOP_DIR}share/doc/libgexf/changelog.Debian.gz" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/share/doc/libgexf
copyFileToTmpDir "README" "${TMPDIR}/${PACKAGE_TOP_DIR}share/doc/libgexf/README" 0644

cd "${TOP}"
makeDirectory ${TMPDIR}//usr/share/doc/libgexf
copyFileToTmpDir "copyright" "${TMPDIR}/${PACKAGE_TOP_DIR}share/doc/libgexf/copyright" 0644


# Create control file
cd "${TOP}"
CONTROL_FILE=${TMPDIR}/DEBIAN/control
rm -f ${CONTROL_FILE}
mkdir -p ${TMPDIR}/DEBIAN

cd "${TOP}"
echo 'Package: libgexf' >> ${CONTROL_FILE}
echo 'Version: 0.1.0' >> ${CONTROL_FILE}
echo 'Architecture: i386' >> ${CONTROL_FILE}
echo 'Section: libdevel' >> ${CONTROL_FILE}
echo 'Priority: extra' >> ${CONTROL_FILE}
echo 'Depends: libxml2, libc6' >> ${CONTROL_FILE}
echo 'Maintainer: sebastien heymann <sebastien.heymann@gephi.org>' >> ${CONTROL_FILE}
echo 'Description: Release 0.1 alpha1 of libgexf.' >> ${CONTROL_FILE}

# Create Debian Package
cd "${TOP}"
cd "${TMPDIR}/.."
dpkg-deb  --build ${TMPDIRNAME}
checkReturnCode
cd "${TOP}"
mkdir -p  dist/Release/${PLATFORM}/package
mv ${TMPDIR}.deb dist/Release/${PLATFORM}/package/libgexf-0.1.0.linux-i386.deb
checkReturnCode
echo Debian: dist/Release/${PLATFORM}/package/libgexf-0.1.0.linux-i386.deb

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}
