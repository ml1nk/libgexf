/*! \file : libgexf.i
    \brief SWIG interface
 */
%module libgexf

%ignore operator<<;
/*%nodefaultdtor;*/

%{
#define SWIG_FILE_WITH_INIT
#include "../../typedefs.h"
#include "../../exceptions.h"
#include "../../graph.h"
#include "../../directedgraph.h"
#include "../../undirectedgraph.h"
#include "../../gexf.h"
%}

%include "std_except.i"
%include "typemaps.i"
/*%include "java.swg"*/

/* Exceptions */


/*%typemap(javabase) ReadLockException "java.lang.Exception";
%typemap(javacode) ReadLockException %{
  public String getMessage() {
    return what();
  }
%}*/

/*%typemap(throws, throws="ReadLockException") ReadLockException {
  jclass clazz = jenv->FindClass("java/lang/Exception");
  jenv->ThrowNew(clazz, $1.what().c_str());
  return $null;
}*/



/*%exception {
  try {
    $action
  } catch (const std::exception& e) {
    jclass excep = jenv->FindClass("java/lang/Exception");
    jenv->ThrowNew(excep, e.what());
    return $null;
  } catch(...) {
    jclass excep = jenv->FindClass("java/lang/Exception");
    jenv->ThrowNew(excep, "Unknown error");
    return $null;
  }
}*/

/*%javaexception("java.lang.Exception") Graph::readLock {
  try {
     $action
  } catch (const ReadLockException& e) {
    jclass clazz = jenv->FindClass("java/lang/Exception");
    jenv->ThrowNew(clazz, e.what());
    return $null;
   }
}*/

%typemap(out) unsigned int &INPUT %{ $result = (jlong)$1; %}
%typemap(out) unsigned int *INPUT %{ $result = (jlong)*$1; %}
%typemap(javaout) unsigned int &INPUT { return $jnicall; }
%typemap(javaout) unsigned int *INPUT { return $jnicall; }



/* Let's just grab the original header file here */
%include "../../typedefs.h"
%include "../../exceptions.h"
%include "../../graph.h"
%include "../../directedgraph.h"
%include "../../undirectedgraph.h"
%include "../../gexf.h"


