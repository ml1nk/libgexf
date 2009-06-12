/*! \file : libgexf.i
    \brief SWIG interface
 */
%module libgexf

%ignore operator<<;
/*%nodefaultdtor;*/

%{
#define SWIG_FILE_WITH_INIT
#include "../../typedefs.h"
#include "../../graph_exceptions.h"
#include "../../graph.h"
#include "../../directedgraph.h"
#include "../../undirectedgraph.h"
#include "../../gexf.h"
%}

%include "std_except.i"
/*%include "std_set.i"*/

%exception {
  try {
    $action
  } catch (const std::exception& e) {
    jclass clazz = jenv->FindClass("java/lang/Exception");
    jenv->ThrowNew(clazz, e.what());
    return $null;
  } catch(...) {
    jclass clazz = jenv->FindClass("java/lang/Exception");
    jenv->ThrowNew(clazz, "Unknown error");
    return $null;
  }
}

/* Let's just grab the original header file here */
%include "../../typedefs.h"
%include "../../graph_exceptions.h"
%include "../../graph.h"
%include "../../directedgraph.h"
%include "../../undirectedgraph.h"
%include "../../gexf.h"
