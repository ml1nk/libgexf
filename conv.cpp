/* 
 * File:   conv.cpp
 * Author: sebastien
 * 
 * Created on 15 juillet 2009, 18:36
 */

#include "conv.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

using namespace std;

namespace libgexf {

Conv::Conv() {
}

Conv::Conv(const Conv& orig) {
}

Conv::~Conv() {
}

//-----------------------------------------
string Conv::xmlCharToStr(const xmlChar* str) {
//-----------------------------------------
    stringstream ss((const char*) str);
    return ss.str();
}

//-----------------------------------------
unsigned int Conv::xmlCharToUnsignedInt(const xmlChar* str) {
//-----------------------------------------
    stringstream ss((const char*) str);
    unsigned int i;
    ss >> i;

    return i;
}

/**
 * convertInput:
 * @in: string in a given encoding
 * @encoding: the encoding used
 *
 * Converts @in into UTF-8 for processing with libxml2 APIs
 *
 * Returns the converted UTF-8 string, or NULL in case of error.
 */
//-----------------------------------------
xmlChar* Conv::convertInput(const char *in, const char *encoding) {
//-----------------------------------------
    xmlChar *out;
    int ret;
    int size;
    int out_size;
    int temp;
    xmlCharEncodingHandlerPtr handler;

    if (in == 0)
        return 0;

    handler = xmlFindCharEncodingHandler(encoding);

    if (!handler) {
        cerr << "convertInput: no encoding handler found for '%s'" << endl << encoding ? encoding : "";
        return 0;
    }

    size = (int) strlen(in) + 1;
    out_size = size * 2 - 1;
    out = (unsigned char *) xmlMalloc((size_t) out_size);

    if (out != 0) {
        temp = size - 1;
        ret = handler->input(out, &out_size, (const xmlChar *) in, &temp);
        if ((ret < 0) || (temp - size + 1)) {
            if (ret < 0) {
                cerr << "convertInput: conversion wasn't successful." << endl;
            } else {
                cerr << "convertInput: conversion wasn't successful. converted: %i octets." << endl << temp << endl;
            }

            xmlFree(out);
            out = 0;
        } else {
            out = (unsigned char *) xmlRealloc(out, out_size + 1);
            out[out_size] = 0;  /*null terminating out */
        }
    } else {
        cerr << "convertInput: no mem" << endl;
    }

    return out;
}


//-----------------------------------------
string Conv::unsignedIntToStr(const unsigned int i) {
//-----------------------------------------
    stringstream ss;
    ss << i;
    return ss.str();
}

//-----------------------------------------
unsigned int Conv::strToUnsignedInt(const string str) {
//-----------------------------------------
    stringstream ss(str.c_str());
    unsigned int i;
    ss >> i;

    return i;
}

//-----------------------------------------
string Conv::edgeTypeToStr(const t_edge_type t) {
//-----------------------------------------
    // fonction de porc qui ne devrait pas exister
    switch(t)
    {
        case EDGE_DIRECTED:
            return "directed";
            break;
        case EDGE_UNDIRECTED:
            return "undirected";
            break;
        case EDGE_DOUBLE:
            return "double";
            break;
    }
    return "";
}

//-----------------------------------------
string Conv::attrTypeToStr(const t_attr_type t) {
//-----------------------------------------
    // fonction de porc qui ne devrait pas exister
    switch(t)
    {
        case INTEGER:
            return "integer";
            break;
        case DOUBLE:
            return "double";
            break;
        case FLOAT:
            return "float";
            break;
        case BOOLEAN:
            return "boolean";
            break;
        case STRING:
            return "string";
            break;
        case LIST_STRING:
            return "list-string";
            break;
    }
    return "";
}

}
