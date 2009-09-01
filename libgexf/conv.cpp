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
#include <cstdio>
#include <cstring>
#include <set>
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
    istringstream iss((const char*) str);
    return (t_id)iss.str();
}

//-----------------------------------------
string Conv::xmlCharToStr(const xmlChar* str) {
//-----------------------------------------
    istringstream iss((const char*) str);
    return iss.str();
}

//-----------------------------------------
t_id Conv::strToId(const std::string& str) {
//-----------------------------------------
    return (t_id)str;
}

//-----------------------------------------
unsigned int Conv::xmlCharToUnsignedInt(const xmlChar* str) {
//-----------------------------------------
    istringstream iss((const char*) str);
    unsigned int i;
    iss >> i;

    return i;
}

//-----------------------------------------
string Conv::idToStr(const t_id id) {
//-----------------------------------------
    return (string)id;
}

//-----------------------------------------
string Conv::unsignedIntToStr(const unsigned int i) {
//-----------------------------------------
    ostringstream oss;
    oss << i;
    return oss.str();
}

//-----------------------------------------
unsigned int Conv::strToUnsignedInt(const std::string& str) {
//-----------------------------------------
    istringstream iss(str.c_str());
    unsigned int i;
    iss >> i;

    return i;
}

//-----------------------------------------
string Conv::edgeTypeToStr(const t_edge_type t) {
//-----------------------------------------
    // fonction de porc qui ne devrait pas exister
    switch(t)
    {
        case EDGE_UNDEF:
            return "undef";
            break;
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
    return "undef";
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
            return "liststring";
            break;
    }
    return "";
}

//-----------------------------------------
bool Conv::isInteger(const std::string& str) {
//-----------------------------------------
    /*stringstream ss(str.c_str());
    int i;
    ss >> i;
    stringstream si;
    si << i;
    
    return si.str() == str;*/

    /* optimized version */
    int i = 0;
    unsigned int nb_char = 0;

    sscanf(str.c_str(), "%d%n", &i, &nb_char);
    return ( str.length() == nb_char );
}

//-----------------------------------------
bool Conv::isDouble(const std::string& str) {
//-----------------------------------------
    double d = 0;
    unsigned int nb_char = 0;

    sscanf(str.c_str(), "%lf%n", &d, &nb_char);
    return ( str.length() == nb_char );
}

//-----------------------------------------
bool Conv::isFloat(const std::string& str) {
//-----------------------------------------
    float f = 0;
    unsigned int nb_char = 0;

    sscanf(str.c_str(), "%f%n", &f, &nb_char);
    return ( str.length() == nb_char );
}

//-----------------------------------------
bool Conv::isBoolean(const std::string& str) {
//-----------------------------------------
    return ( str == "true" || str == "false" );
}

//-----------------------------------------
std::set<std::string> Conv::tokenizer(const std::string& delimiter, const std::string& str) {
//-----------------------------------------
    std::set<string> tokens;
    char* const cstr = new char [str.size()+1];
    strcpy( cstr, str.c_str() );
    char* tokenPtr = strtok(cstr,"|");
    
    while( tokenPtr != NULL ) {
        tokens.insert(tokenPtr);
        tokenPtr = strtok(NULL, "|");
    }
    delete[] cstr;

    return tokens;
}

}
