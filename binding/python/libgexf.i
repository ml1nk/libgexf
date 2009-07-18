/*! \file : libgexf.i
    \brief SWIG interface
 */
%module libgexf

%ignore operator<<;
/*%nodefaultdtor;*/

%{
#define SWIG_FILE_WITH_INIT
/* main */
#include "../../typedefs.h"
#include "../../exceptions.h"
#include "../../gexf.h"
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


%include <pyabc.i>
%include stl.i
%include exception.i
%include std_string.i
%include std_set.i

%exception {
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  } catch(...) {
    SWIG_exception(SWIG_RuntimeError, "Unknown error");
  }
}

namespace std {
  %template(StringSet) std::set<std::string>;
}

/* Let's just grab the original header file here */
/* main */
%include "../../typedefs.h"
%include "../../exceptions.h"
%include "../../gexf.h"
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


