/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.gephi.libgexf;

public class SchemaValidator {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected SchemaValidator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SchemaValidator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        libgexfJNI.delete_SchemaValidator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public static boolean run(String xml_file_pathname, String xml_schema_file_pathname) {
    return libgexfJNI.SchemaValidator_run(xml_file_pathname, xml_schema_file_pathname);
  }

}