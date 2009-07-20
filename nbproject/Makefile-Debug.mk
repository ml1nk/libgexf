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
OBJECTDIR=build/Debug/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/filereader.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/attvalueiter.o \
	${OBJECTDIR}/directedgraph.o \
	${OBJECTDIR}/undirectedgraph.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/edgeiter.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/attributeiter.o \
	${OBJECTDIR}/graph.o \
	${OBJECTDIR}/gexfparser.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/data.o \
	${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/conv.o \
	${OBJECTDIR}/gexf.o \
	${OBJECTDIR}/legacyparser.o \
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
LDLIBSOPTIONS=/usr/lib/libxml2.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/${PLATFORM}/libgexf.so

dist/Debug/${PLATFORM}/libgexf.so: /usr/lib/libxml2.so

dist/Debug/${PLATFORM}/libgexf.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/${PLATFORM}
	${LINK.cc} -shared -o dist/Debug/${PLATFORM}/libgexf.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/filereader.o: filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/filereader.o filereader.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/attvalueiter.o: /home/sebastien/NetBeansProjects/libgexf/attvalueiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/attvalueiter.o /home/sebastien/NetBeansProjects/libgexf/attvalueiter.cpp

${OBJECTDIR}/directedgraph.o: directedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/directedgraph.o directedgraph.cpp

${OBJECTDIR}/undirectedgraph.o: undirectedgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/undirectedgraph.o undirectedgraph.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/edgeiter.o: /home/sebastien/NetBeansProjects/libgexf/edgeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/edgeiter.o /home/sebastien/NetBeansProjects/libgexf/edgeiter.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/attributeiter.o: /home/sebastien/NetBeansProjects/libgexf/attributeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/attributeiter.o /home/sebastien/NetBeansProjects/libgexf/attributeiter.cpp

${OBJECTDIR}/graph.o: graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/graph.o graph.cpp

${OBJECTDIR}/gexfparser.o: gexfparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/gexfparser.o gexfparser.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/data.o: /home/sebastien/NetBeansProjects/libgexf/data.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/data.o /home/sebastien/NetBeansProjects/libgexf/data.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/conv.o: /home/sebastien/NetBeansProjects/libgexf/conv.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/conv.o /home/sebastien/NetBeansProjects/libgexf/conv.cpp

${OBJECTDIR}/gexf.o: gexf.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/gexf.o gexf.cpp

${OBJECTDIR}/legacyparser.o: legacyparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/legacyparser.o legacyparser.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/nodeiter.o: /home/sebastien/NetBeansProjects/libgexf/nodeiter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/nodeiter.o /home/sebastien/NetBeansProjects/libgexf/nodeiter.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/filewriter.o: /home/sebastien/NetBeansProjects/libgexf/filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/filewriter.o /home/sebastien/NetBeansProjects/libgexf/filewriter.cpp

${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/metadata.o: /home/sebastien/NetBeansProjects/libgexf/metadata.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include/libxml2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/sebastien/NetBeansProjects/libgexf/metadata.o /home/sebastien/NetBeansProjects/libgexf/metadata.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/${PLATFORM}/libgexf.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
