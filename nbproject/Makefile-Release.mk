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
OBJECTDIR=build/Release/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/filereader.o \
	${OBJECTDIR}/undirectedgraph.o \
	${OBJECTDIR}/directedgraph.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/edgeiter.o \
	${OBJECTDIR}/graph.o \
	${OBJECTDIR}/gexfparser.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/data.o \
	${OBJECTDIR}/inserters.o \
	${OBJECTDIR}/gexf.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/nodeiter.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/filewriter.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/metadata.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/${PLATFORM}/liblibgexf.a

dist/Release/${PLATFORM}/liblibgexf.a: ${OBJECTFILES}
	${MKDIR} -p dist/Release/${PLATFORM}
	${RM} dist/Release/${PLATFORM}/liblibgexf.a
	${AR} rv dist/Release/${PLATFORM}/liblibgexf.a ${OBJECTFILES} 
	$(RANLIB) dist/Release/${PLATFORM}/liblibgexf.a

${OBJECTDIR}/filereader.o: filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/filereader.o filereader.cpp

${OBJECTDIR}/undirectedgraph.o: undirectedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/undirectedgraph.o undirectedgraph.cpp

${OBJECTDIR}/directedgraph.o: directedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/directedgraph.o directedgraph.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/edgeiter.o: /home/sebastien/NetBeansProjects/libgexf/edgeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/edgeiter.o /home/sebastien/NetBeansProjects/libgexf/edgeiter.cpp

${OBJECTDIR}/graph.o: graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/graph.o graph.cpp

${OBJECTDIR}/gexfparser.o: gexfparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/gexfparser.o gexfparser.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/data.o: /home/sebastien/NetBeansProjects/libgexf/data.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/data.o /home/sebastien/NetBeansProjects/libgexf/data.cpp

${OBJECTDIR}/inserters.o: inserters.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/inserters.o inserters.cpp

${OBJECTDIR}/gexf.o: gexf.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/gexf.o gexf.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/nodeiter.o: /home/sebastien/NetBeansProjects/libgexf/nodeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/nodeiter.o /home/sebastien/NetBeansProjects/libgexf/nodeiter.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/filewriter.o: /home/sebastien/NetBeansProjects/libgexf/filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/filewriter.o /home/sebastien/NetBeansProjects/libgexf/filewriter.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/metadata.o: /home/sebastien/NetBeansProjects/libgexf/metadata.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/metadata.o /home/sebastien/NetBeansProjects/libgexf/metadata.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/${PLATFORM}/liblibgexf.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
