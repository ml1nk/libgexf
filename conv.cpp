/*! \file conv.cpp
    \author sebastien heymann
    \date 15 juillet 2009, 18:36
    \version 0.1
 */

/*
# Copyright (c) <2009> <Sebastien Heymann>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
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
t_id Conv::xmlCharToId(const xmlChar* str) {
//-----------------------------------------
    stringstream ss((const char*) str);
    return (t_id)ss.str();
}

//-----------------------------------------
string Conv::xmlCharToStr(const xmlChar* str) {
//-----------------------------------------
    stringstream ss((const char*) str);
    return ss.str();
}

//-----------------------------------------
t_id Conv::strToId(const string str) {
//-----------------------------------------
    return (t_id)str;
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
string Conv::idToStr(const t_id id) {
//-----------------------------------------
    return (string)id;
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
