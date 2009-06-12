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

%include "exception.i"
%include "std_set.i"

%exception {
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  } catch(...) {
    SWIG_exception(SWIG_RuntimeError, "Unknown error");
  }
}

/* Let's just grab the original header file here */
%include "../../typedefs.h"
%include "../../graph_exceptions.h"
%include "../../graph.h"
%include "../../directedgraph.h"
%include "../../undirectedgraph.h"
%include "../../gexf.h"
