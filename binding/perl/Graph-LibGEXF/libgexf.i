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
/* main */
#include "../../typedefs.h"
#include "../../exceptions.h"
#include "../../gexf.h"
#include "../../abstractiter.h"
/* io::input */
#include "../../filereader.h"
#include "../../abstractparser.h"
#include "../../gexfparser.h"
#include "../../legacyparser.h"
/* io::output */
#include "../../filewriter.h"
/* io::utils */
#include "../../conv.h"
/* db::topo */
#include "../../graph.h"
#include "../../directedgraph.h"
#include "../../undirectedgraph.h"
#include "../../nodeiter.h"
#include "../../edgeiter.h"
/* db::data */
#include "../../data.h"
#include "../../metadata.h"
#include "../../attributeiter.h"
#include "../../attvalueiter.h"
%}

%include typemaps.i
%include stl.i
%include exception.i
%include std_except.i

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
/* main */
%include "../../typedefs.h"
%include "../../exceptions.h"
%include "../../gexf.h"
%include "../../abstractiter.h"
/* io::input */
%include "../../filereader.h"
%include "../../abstractparser.h"
%include "../../gexfparser.h"
%include "../../legacyparser.h"
/* io::output */
%include "../../filewriter.h"
/* io::utils */
%include "../../conv.h"
/* db::topo */
%include "../../graph.h"
%include "../../directedgraph.h"
%include "../../undirectedgraph.h"
%include "../../nodeiter.h"
%include "../../edgeiter.h"
/* db::data */
%include "../../data.h"
%include "../../metadata.h"
%include "../../attributeiter.h"
%include "../../attvalueiter.h"

