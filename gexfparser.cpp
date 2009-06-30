/*! \file gexfparser.cpp
    \author sebastien heymann
    \date 22 juin 2009, 17:20
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

#include "gexfparser.h"
#include "reader.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

namespace libgexf {

GexfParser::GexfParser(): _ancestor("") {
}

GexfParser::GexfParser(const GexfParser& orig): _ancestor(orig._ancestor) {
}

GexfParser::~GexfParser() {
    // do not delete _gexf, only Reader instance should do !!
}

//-----------------------------------------
void GexfParser::bind(GEXF* gexf) {
//-----------------------------------------
    _gexf = gexf;
}

/**
 * processNode:
 * @reader: the xmlReader
 *
 * Call the right processing method
 */
//-----------------------------------------
void GexfParser::processNode(xmlTextReaderPtr reader, const xmlChar* name) {
//-----------------------------------------
    if( !isProcessableNode(reader) ) return;
    
    if( xmlStrEqual(name, xmlCharStrdup("gexf")) == 1 ) {
        processGEXFNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("meta")) == 1 ) {
        processMetaNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("creator")) == 1 ) {
        processCreatorNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("description")) == 1 ) {
        processDescriptionNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("graph")) == 1 ) {
        processGraphNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("nodes")) == 1 ) {
        processNodesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("node")) == 1 ) {
        processNodeNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("edges")) == 1 ) {
        processEdgesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("edge")) == 1 ) {
        processEdgeNode(reader);
    }
    // TODO: other xml nodes
}

//-----------------------------------------
void GexfParser::processGEXFNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        xmlChar* attr_xmlns = xmlTextReaderGetAttribute(reader, xmlCharStrdup("xmlns"));
        if(attr_xmlns != NULL)
            _gexf->getMetaData().setXmlns( xmlCharToStr(attr_xmlns) );

        xmlChar* attr_xsi = xmlTextReaderGetAttributeNs(reader, xmlCharStrdup("xsi"), xmlCharStrdup("xmlns"));
        printf("attr_xsi=%s\n",attr_xsi);
        if(attr_xsi != NULL)
            _gexf->getMetaData().setXsi( xmlCharToStr(attr_xsi) );

        xmlChar* attr_schema = xmlTextReaderGetAttributeNs(reader, xmlCharStrdup("schemaLocation"), xmlCharStrdup("xmlns"));
        if(attr_schema != NULL)
            _gexf->getMetaData().setSchema( xmlCharToStr(attr_schema) );

        xmlChar* attr_version = xmlTextReaderGetAttribute(reader, xmlCharStrdup("version"));
        //printf("version: %s\n", attr_version);
        if(attr_version != NULL)
            _gexf->getMetaData().setVersion( xmlCharToStr(attr_version) );
    }
    else if(hasAttr  == -1) {
        throw "An error occured in xmlTextReaderHasAttributes() for GEXF node.";
    }

}

//-----------------------------------------
void GexfParser::processMetaNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        xmlChar* attr_lastmodifieddate = xmlTextReaderGetAttribute(reader, xmlCharStrdup("lastmodifieddate"));
        if(attr_lastmodifieddate != NULL)
            _gexf->getMetaData().setLastModifiedDate( xmlCharToStr(attr_lastmodifieddate) );
    }
    else if(hasAttr  == -1) {
        throw "An error occured in xmlTextReaderHasAttributes() for Meta node.";
    }
}

//-----------------------------------------
void GexfParser::processCreatorNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasVal = xmlTextReaderHasValue(reader);
    if(hasVal == 1) {
        const xmlChar *value = xmlTextReaderConstValue(reader);
        if(value != NULL)
            _gexf->getMetaData().setCreator( xmlCharToStr(value) );
    }
    else if(hasVal  == -1) {
        throw "An error occured in xmlTextReaderHasValue() for Creator node.";
    }
}

//-----------------------------------------
void GexfParser::processDescriptionNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasVal = xmlTextReaderHasValue(reader);
    if(hasVal == 1) {
        const xmlChar *value = xmlTextReaderConstValue(reader);
        if(value != NULL) {
            _gexf->getMetaData().setDescription( xmlCharToStr(value) );
        }
    }
    else if(hasVal  == -1) {
        throw "An error occured in xmlTextReaderHasValue() for Description node.";
    }
}

//-----------------------------------------
void GexfParser::processGraphNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    _gexf->setGraphType(GRAPH_UNDIRECTED); /* default */
    
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        xmlChar* attr_mode = xmlTextReaderGetAttribute(reader, xmlCharStrdup("mode"));
        //printf("mode: %s\n", attr_mode);
        // TODO gere les modes

        xmlChar* attr_defaultedgetype = xmlTextReaderGetAttribute(reader, xmlCharStrdup("defaultedgetype"));
        //printf("defaultedgetype: %s\n", attr_defaultedgetype);

        if( attr_defaultedgetype != NULL && xmlStrEqual(attr_defaultedgetype, xmlCharStrdup("directed")) == 1 ) {
            _gexf->setGraphType(GRAPH_DIRECTED);
        }
    }
    else if(hasAttr  == -1) {
        throw "An error occured in xmlTextReaderHasAttributes() for Graph node.";
    }
}

//-----------------------------------------
void GexfParser::processNodesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    // TODO, do nothing for the moment
}

//-----------------------------------------
void GexfParser::processNodeNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        xmlChar* attr_id = xmlTextReaderGetAttribute(reader, xmlCharStrdup("id"));
        t_id node_id = (t_id)xmlCharToUnsignedInt(attr_id);

        xmlChar* attr_label = xmlTextReaderGetAttribute(reader, xmlCharStrdup("label"));
        //printf("label: %s\n", attr_label);

        _gexf->getUndirectedGraph().addNode( node_id );
        _gexf->getData().setLabel( node_id, xmlCharToStr(attr_label) );
    }
    else if(hasAttr  == -1) {
        throw "An error occured in xmlTextReaderHasAttributes() for Graph node.";
    }
}

//-----------------------------------------
void GexfParser::processEdgesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    // TODO, do nothing for the moment
}

//-----------------------------------------
void GexfParser::processEdgeNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        xmlChar* attr_id = xmlTextReaderGetAttribute(reader, xmlCharStrdup("id"));
        //printf("id: %s\n", attr_id);

        xmlChar* attr_source = xmlTextReaderGetAttribute(reader, xmlCharStrdup("source"));
        //printf("source: %s\n", attr_source);

        xmlChar* attr_target = xmlTextReaderGetAttribute(reader, xmlCharStrdup("target"));
        //printf("target: %s\n", attr_target);
        
        if(_gexf->getGraphType() == GRAPH_DIRECTED) {
            _gexf->getDirectedGraph().addEdge( (t_id)xmlCharToUnsignedInt(attr_id), (t_id)xmlCharToUnsignedInt(attr_source), (t_id)xmlCharToUnsignedInt(attr_target) );
        }
        else { /*default: undirected*/
            _gexf->getUndirectedGraph().addEdge( (t_id)xmlCharToUnsignedInt(attr_id), (t_id)xmlCharToUnsignedInt(attr_source), (t_id)xmlCharToUnsignedInt(attr_target) );
        }
    }
    else if(hasAttr  == -1) {
        throw "An error occured in xmlTextReaderHasAttributes() for Graph node.";
    }
}

//-----------------------------------------
bool GexfParser::isProcessableNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    /* for XmlNodeType, see http://www.gnu.org/software/dotgnu/pnetlib-doc/System/Xml/XmlNodeType.html
     */
    int t = xmlTextReaderNodeType(reader);
    return t != 15 && t != 16 && t != 12 && t != 13 && t != 7;
}

//-----------------------------------------
string GexfParser::xmlCharToStr(const xmlChar* str) {
//-----------------------------------------
    stringstream ss((const char*) str);
    return ss.str();
}

//-----------------------------------------
unsigned int GexfParser::xmlCharToUnsignedInt(const xmlChar* str) {
//-----------------------------------------
    stringstream ss((const char*) str);
    unsigned int i;
    ss >> i;
    
    return i;
}

} /* namespace libgexf */
