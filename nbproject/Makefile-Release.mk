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
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include nbproject/Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/libgexf/rngvalidator.o \
	${OBJECTDIR}/libgexf/gexf.o \
	${OBJECTDIR}/libgexf/nodeiter.o \
	${OBJECTDIR}/libgexf/filereader.o \
	${OBJECTDIR}/libgexf/legacywriter.o \
	${OBJECTDIR}/libgexf/attvalueiter.o \
	${OBJECTDIR}/libgexf/attributeiter.o \
	${OBJECTDIR}/libgexf/filewriter.o \
	${OBJECTDIR}/libgexf/schemavalidator.o \
	${OBJECTDIR}/libgexf/metadata.o \
	${OBJECTDIR}/libgexf/data.o \
	${OBJECTDIR}/libgexf/gexfparser.o \
	${OBJECTDIR}/libgexf/conv.o \
	${OBJECTDIR}/libgexf/edgeiter.o \
	${OBJECTDIR}/libgexf/memoryvalidator.o \
	${OBJECTDIR}/libgexf/undirectedgraph.o \
	${OBJECTDIR}/libgexf/abstractparser.o \
	${OBJECTDIR}/libgexf/directedgraph.o \
	${OBJECTDIR}/libgexf/legacyparser.o \
	${OBJECTDIR}/libgexf/graph.o

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
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/libgexf.so

dist/Release/GNU-Linux-x86/libgexf.so: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -shared -o dist/Release/${PLATFORM}/libgexf.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/libgexf/rngvalidator.o: nbproject/Makefile-${CND_CONF}.mk libgexf/rngvalidator.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/rngvalidator.o libgexf/rngvalidator.cpp

${OBJECTDIR}/libgexf/gexf.o: nbproject/Makefile-${CND_CONF}.mk libgexf/gexf.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/gexf.o libgexf/gexf.cpp

${OBJECTDIR}/libgexf/nodeiter.o: nbproject/Makefile-${CND_CONF}.mk libgexf/nodeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/nodeiter.o libgexf/nodeiter.cpp

${OBJECTDIR}/libgexf/filereader.o: nbproject/Makefile-${CND_CONF}.mk libgexf/filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/filereader.o libgexf/filereader.cpp

${OBJECTDIR}/libgexf/legacywriter.o: nbproject/Makefile-${CND_CONF}.mk libgexf/legacywriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/legacywriter.o libgexf/legacywriter.cpp

${OBJECTDIR}/libgexf/attvalueiter.o: nbproject/Makefile-${CND_CONF}.mk libgexf/attvalueiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/attvalueiter.o libgexf/attvalueiter.cpp

${OBJECTDIR}/libgexf/attributeiter.o: nbproject/Makefile-${CND_CONF}.mk libgexf/attributeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/attributeiter.o libgexf/attributeiter.cpp

${OBJECTDIR}/libgexf/filewriter.o: nbproject/Makefile-${CND_CONF}.mk libgexf/filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/filewriter.o libgexf/filewriter.cpp

${OBJECTDIR}/libgexf/schemavalidator.o: nbproject/Makefile-${CND_CONF}.mk libgexf/schemavalidator.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/schemavalidator.o libgexf/schemavalidator.cpp

${OBJECTDIR}/libgexf/metadata.o: nbproject/Makefile-${CND_CONF}.mk libgexf/metadata.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/metadata.o libgexf/metadata.cpp

${OBJECTDIR}/libgexf/data.o: nbproject/Makefile-${CND_CONF}.mk libgexf/data.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/data.o libgexf/data.cpp

${OBJECTDIR}/libgexf/gexfparser.o: nbproject/Makefile-${CND_CONF}.mk libgexf/gexfparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/gexfparser.o libgexf/gexfparser.cpp

${OBJECTDIR}/libgexf/conv.o: nbproject/Makefile-${CND_CONF}.mk libgexf/conv.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/conv.o libgexf/conv.cpp

${OBJECTDIR}/libgexf/edgeiter.o: nbproject/Makefile-${CND_CONF}.mk libgexf/edgeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/edgeiter.o libgexf/edgeiter.cpp

${OBJECTDIR}/libgexf/memoryvalidator.o: nbproject/Makefile-${CND_CONF}.mk libgexf/memoryvalidator.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/memoryvalidator.o libgexf/memoryvalidator.cpp

${OBJECTDIR}/libgexf/undirectedgraph.o: nbproject/Makefile-${CND_CONF}.mk libgexf/undirectedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/undirectedgraph.o libgexf/undirectedgraph.cpp

${OBJECTDIR}/libgexf/abstractparser.o: nbproject/Makefile-${CND_CONF}.mk libgexf/abstractparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/abstractparser.o libgexf/abstractparser.cpp

${OBJECTDIR}/libgexf/directedgraph.o: nbproject/Makefile-${CND_CONF}.mk libgexf/directedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/directedgraph.o libgexf/directedgraph.cpp

${OBJECTDIR}/libgexf/legacyparser.o: nbproject/Makefile-${CND_CONF}.mk libgexf/legacyparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/legacyparser.o libgexf/legacyparser.cpp

${OBJECTDIR}/libgexf/graph.o: nbproject/Makefile-${CND_CONF}.mk libgexf/graph.cpp 
	${MKDIR} -p ${OBJECTDIR}/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/libgexf/graph.o libgexf/graph.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/libgexf.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
