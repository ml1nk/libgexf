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
AS=

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/gexf.o \
	${OBJECTDIR}/src/filereader.o \
	${OBJECTDIR}/src/legacyparser.o \
	${OBJECTDIR}/src/gexfparser.o \
	${OBJECTDIR}/src/undirectedgraph.o \
	${OBJECTDIR}/src/filewriter.o \
	${OBJECTDIR}/src/data.o \
	${OBJECTDIR}/src/rngvalidator.o \
	${OBJECTDIR}/src/graph.o \
	${OBJECTDIR}/src/edgeiter.o \
	${OBJECTDIR}/src/conv.o \
	${OBJECTDIR}/src/nodeiter.o \
	${OBJECTDIR}/src/schemavalidator.o \
	${OBJECTDIR}/src/attributeiter.o \
	${OBJECTDIR}/src/metadata.o \
	${OBJECTDIR}/src/attvalueiter.o \
	${OBJECTDIR}/src/directedgraph.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lxml2

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libgexf.so

dist/Debug/GNU-Linux-x86/libgexf.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -shared -o dist/Debug/${PLATFORM}/libgexf.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/gexf.o: nbproject/Makefile-${CND_CONF}.mk src/gexf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gexf.o src/gexf.cpp

${OBJECTDIR}/src/filereader.o: nbproject/Makefile-${CND_CONF}.mk src/filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/filereader.o src/filereader.cpp

${OBJECTDIR}/src/legacyparser.o: nbproject/Makefile-${CND_CONF}.mk src/legacyparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/legacyparser.o src/legacyparser.cpp

${OBJECTDIR}/src/gexfparser.o: nbproject/Makefile-${CND_CONF}.mk src/gexfparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gexfparser.o src/gexfparser.cpp

${OBJECTDIR}/src/undirectedgraph.o: nbproject/Makefile-${CND_CONF}.mk src/undirectedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/undirectedgraph.o src/undirectedgraph.cpp

${OBJECTDIR}/src/filewriter.o: nbproject/Makefile-${CND_CONF}.mk src/filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/filewriter.o src/filewriter.cpp

${OBJECTDIR}/src/data.o: nbproject/Makefile-${CND_CONF}.mk src/data.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/data.o src/data.cpp

${OBJECTDIR}/src/rngvalidator.o: nbproject/Makefile-${CND_CONF}.mk src/rngvalidator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rngvalidator.o src/rngvalidator.cpp

${OBJECTDIR}/src/graph.o: nbproject/Makefile-${CND_CONF}.mk src/graph.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graph.o src/graph.cpp

${OBJECTDIR}/src/edgeiter.o: nbproject/Makefile-${CND_CONF}.mk src/edgeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/edgeiter.o src/edgeiter.cpp

${OBJECTDIR}/src/conv.o: nbproject/Makefile-${CND_CONF}.mk src/conv.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/conv.o src/conv.cpp

${OBJECTDIR}/src/nodeiter.o: nbproject/Makefile-${CND_CONF}.mk src/nodeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/nodeiter.o src/nodeiter.cpp

${OBJECTDIR}/src/schemavalidator.o: nbproject/Makefile-${CND_CONF}.mk src/schemavalidator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/schemavalidator.o src/schemavalidator.cpp

${OBJECTDIR}/src/attributeiter.o: nbproject/Makefile-${CND_CONF}.mk src/attributeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/attributeiter.o src/attributeiter.cpp

${OBJECTDIR}/src/metadata.o: nbproject/Makefile-${CND_CONF}.mk src/metadata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/metadata.o src/metadata.cpp

${OBJECTDIR}/src/attvalueiter.o: nbproject/Makefile-${CND_CONF}.mk src/attvalueiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/attvalueiter.o src/attvalueiter.cpp

${OBJECTDIR}/src/directedgraph.o: nbproject/Makefile-${CND_CONF}.mk src/directedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/directedgraph.o src/directedgraph.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libgexf.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
