/* 
 * File:   schemavalidator.cpp
 * Author: sebastien
 * 
 * Created on 31 juillet 2009, 01:19
 */

#include "schemavalidator.h"
#include <iostream>

using namespace std;

namespace libgexf {

SchemaValidator::SchemaValidator() {
}

SchemaValidator::SchemaValidator(const SchemaValidator& orig) {
}

SchemaValidator::~SchemaValidator() {
}

// libxml error handler
//-----------------------------------------
void SchemaValidator::schemaErrorCallback(void*, const char* msg, xmlParserSeverities severity, xmlTextReaderLocatorPtr locator) {
//-----------------------------------------
  cerr << "WARN " << "Schema error: " << msg << endl;
}

// libxml warning handler
//-----------------------------------------
void SchemaValidator::schemaWarningCallback(void* callbackData, const char* msg, xmlParserSeverities severity, xmlTextReaderLocatorPtr locator) {
//-----------------------------------------
    cerr << "WARN " << "Schema warning: " << msg << endl;
}

// Returns true if file validated successfully, false otherwise
//-----------------------------------------
bool SchemaValidator::run(const std::string xml_file_pathname, const std::string xml_schema_file_pathname) {
//-----------------------------------------
    // TODO handle multiple XSD files (eg viz)
    bool result = false;
    if (xmlSchemaParserCtxt* schemaParser = xmlSchemaNewParserCtxt(xml_schema_file_pathname.c_str())) {
        if (xmlSchema* schema = xmlSchemaParse(schemaParser)) {
          if (xmlSchemaValidCtxt* validityContext = xmlSchemaNewValidCtxt(schema)) {
            xmlSchemaSetValidErrors(validityContext,
                                   (xmlSchemaValidityErrorFunc)SchemaValidator::schemaErrorCallback,
                                   (xmlSchemaValidityWarningFunc)SchemaValidator::schemaWarningCallback,
                                   NULL);

                // Returns 0 if validation succeeded
                result = xmlSchemaValidateFile(validityContext, xml_file_pathname.c_str(), 0) == 0;
                xmlSchemaFreeValidCtxt(validityContext);
            }
            xmlSchemaFree(schema);
        }
        xmlSchemaFreeParserCtxt(schemaParser);
    }

    return result;
}



    /*xmlTextReaderPtr reader;
    int ret;

    reader = xmlReaderForFile(xml_file_pathname, NULL, 0);
    if (reader != NULL) {
        xmlSchemaParserCtxt ctxt = xmlSchemaNewParserCtxt(xml_schema_file_pathname.c_str());

        xmlSchemaPtr schema = xmlSchemaParse(ctxt);
        xmlSchemaValidCtxtPtr valid_ctxt =  xmlSchemaNewValidCtxt(schema);


        xmlTextReaderSchemaValidateCtxt(reader, );
        xmlTextReaderSchemaValidate(reader, );

        while (xmlTextReaderRead(reader));
        xmlFreeTextReader(reader);

        
    } else {
        throw "Unable to open " + xml_file_pathname;
    }*/


/*	xmlSchemaPtr ptr_schema = NULL;
	xmlSchemaParserCtxtPtr ptr_ctxt;
	xmlSchemaValidCtxtPtr ptr_validctxt;
	int vl_return;
	xmlDocPtr vl_doc;
	HINSTANCE vl_hModule;


	// open the XML Schema file /
	ptr_ctxt = xmlSchemaNewParserCtxt(xml_schema_file_pathname);
	xmlSchemaSetParserErrors(ptr_ctxt,
	    (xmlSchemaValidityErrorFunc) fprintf,
	    (xmlSchemaValidityWarningFunc) fprintf,
	    stderr);

	ptr_schema = xmlSchemaParse(ptr_ctxt);
	xmlSchemaFreeParserCtxt(ptr_ctxt);

	// if the XML Schema file is not readable/
	if (ptr_schema == NULL) {
		cerr << "WARN " << "RngValidator: Could not open XML Schema " << xml_schema_file_pathname << endl;
		xmlSchemaCleanupTypes();
		xmlCleanupParser();
		xmlMemoryDump();
		FreeLibrary(vl_hModule);
		return -1;
	}

	vl_doc =xmlReadFile(xml_file_pathname,NULL,0);
	// if the XML file can't be parsed/
	if (vl_doc == NULL) {
	    cerr << "WARN " << "XML: Could not parse " << xml_file_pathname << endl;
	}
        else { // validate the file /
		// Chargement du contenu du XML SChema  /
		ptr_validctxt = xmlSchemaNewValidCtxt(ptr_schema);
		xmlSchemaSetValidErrors(ptr_validctxt,
		    (xmlSchemaValidityErrorFunc) fprintf,
		    (xmlSchemaValidityWarningFunc) fprintf,
		    stderr);

		// validation based on the XML Schema structure /
		vl_return = (fct_xmlSchemaValidateDoc)(ptr_validctxt, vl_doc);

		// print result /
		if (vl_return == 0){ // if the XML file is valid
			cout << "INFO " << "RngValidator: Xml file " << xml_file_pathname << " validates." << endl;
		}
                else if (vl_return > 0){ // if the XML doesn't correspond to the XSD structure
                        cout << "INFO " << "RngValidator: Xml file " << xml_file_pathname << " fails to validate." << endl;
		}
                else { // other error
                        cout << "INFO " << "RngValidator: " << xml_file_pathname << " validation generated an internal error." << endl;
		}
		xmlSchemaFreeValidCtxt(ptr_validctxt);
		xmlFreeDoc(vl_doc);
	}

	FreeLibrary(vl_hModule);
	return(0);
}*/


} /* namespace libgexf */
