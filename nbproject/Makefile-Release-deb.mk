#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Macros
PLATFORM=GNU-Linux-x86

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Release-deb/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/filereader.o \
	${OBJECTDIR}/attvalueiter.o \
	${OBJECTDIR}/directedgraph.o \
	${OBJECTDIR}/undirectedgraph.o \
	${OBJECTDIR}/edgeiter.o \
	${OBJECTDIR}/attributeiter.o \
	${OBJECTDIR}/graph.o \
	${OBJECTDIR}/gexfparser.o \
	${OBJECTDIR}/data.o \
	${OBJECTDIR}/conv.o \
	${OBJECTDIR}/gexf.o \
	${OBJECTDIR}/legacyparser.o \
	${OBJECTDIR}/nodeiter.o \
	${OBJECTDIR}/filewriter.o \
	${OBJECTDIR}/metadata.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lxml2

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release-deb.mk dist/Release/${PLATFORM}/libgexf.so

dist/Release/${PLATFORM}/libgexf.so: ${OBJECTFILES}
	${MKDIR} -p dist/Release/${PLATFORM}
	${LINK.cc} -shared -o dist/Release/${PLATFORM}/libgexf.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/filereader.o: src/filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/filereader.o src/filereader.cpp

${OBJECTDIR}/attvalueiter.o: src/attvalueiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/attvalueiter.o src/attvalueiter.cpp

${OBJECTDIR}/directedgraph.o: src/directedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/directedgraph.o src/directedgraph.cpp

${OBJECTDIR}/undirectedgraph.o: src/undirectedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/undirectedgraph.o src/undirectedgraph.cpp

${OBJECTDIR}/edgeiter.o: src/edgeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/edgeiter.o src/edgeiter.cpp

${OBJECTDIR}/attributeiter.o: src/attributeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/attributeiter.o src/attributeiter.cpp

${OBJECTDIR}/graph.o: src/graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/graph.o src/graph.cpp

${OBJECTDIR}/gexfparser.o: src/gexfparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/gexfparser.o src/gexfparser.cpp

${OBJECTDIR}/data.o: src/data.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/data.o src/data.cpp

${OBJECTDIR}/conv.o: src/conv.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/conv.o src/conv.cpp

${OBJECTDIR}/gexf.o: src/gexf.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/gexf.o src/gexf.cpp

${OBJECTDIR}/legacyparser.o: src/legacyparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/legacyparser.o src/legacyparser.cpp

${OBJECTDIR}/nodeiter.o: src/nodeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/nodeiter.o src/nodeiter.cpp

${OBJECTDIR}/filewriter.o: src/filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/filewriter.o src/filewriter.cpp

${OBJECTDIR}/metadata.o: src/metadata.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/metadata.o src/metadata.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release-deb
	${RM} dist/Release/${PLATFORM}/libgexf.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
