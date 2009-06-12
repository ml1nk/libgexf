/*! \file : libgexf.i
    \brief SWIG interface
 */
%module "Graph::LibGEXF"

%ignore operator<<;
/*%nodefaultdtor;*/

%{
#define SWIG_FILE_WITH_INIT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "../../../typedefs.h"
#include "../../../graph_exceptions.h"
#include "../../../graph.h"
#include "../../../directedgraph.h"
#include "../../../undirectedgraph.h"
#include "../../../gexf.h"
%}

%include "std_except.i"
/*%include "std_set.i"*/

%exception {
  try {
    $action
  }
  catch (const std::exception& e) {
    SWIG_croak(e.what());
  } catch(...) {
    SWIG_croak("Unknown error");
  }
}


/* Let's just grab the original header file here */
%include "../../../typedefs.h"
%include "../../../graph_exceptions.h"
%include "../../../graph.h"
%include "../../../directedgraph.h"
%include "../../../undirectedgraph.h"
%include "../../../gexf.h"

