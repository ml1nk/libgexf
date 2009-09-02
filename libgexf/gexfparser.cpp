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
#include "filereader.h"
#include "conv.h"
#include "data.h"
#include <string>
using namespace std;

namespace libgexf {

GexfParser::GexfParser(): _last_node_type(), _last_id() {
}

GexfParser::GexfParser(const GexfParser& orig): _last_node_type(orig._last_node_type), _last_id(orig._last_id) {
}

GexfParser::~GexfParser() {
    // do not delete _gexf, only Reader instance should do it!
}

//-----------------------------------------
void GexfParser::bind(GEXF* gexf) {
//-----------------------------------------
    _gexf = gexf;
}

//-----------------------------------------
void GexfParser::processNode(xmlTextReaderPtr reader, const xmlChar* const name) {
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
    else if( xmlStrEqual(name, xmlCharStrdup("attributes")) == 1 ) {
        processAttributesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attribute")) == 1 ) {
        processAttributeNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("default")) == 1 ) {
        processAttributeDefaultNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("options")) == 1 ) {
        processAttributeOptionsNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attvalues")) == 1 ) {
        processAttvaluesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attvalue")) == 1 ) {
        processAttvalueNode(reader);
    }
}

//-----------------------------------------
void GexfParser::processGEXFNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        /* useless */
        /*try {
            string xmlns = this->getStringAttribute(reader, "xmlns");
            _gexf->getMetaData().setXmlns( xmlns );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }

        try {
            string xsi = this->getStringAttribute(reader, "xmlns:xsi");
            _gexf->getMetaData().setXsi( xsi );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }

        try {
            string schemaLocation = this->getStringAttribute(reader, "xsi:schemaLocation");
            _gexf->getMetaData().setXsi( schemaLocation );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }*/

        string version = "1.1";
        try {
            version = this->getStringAttribute(reader, "version");
            //_gexf->getMetaData().setVersion( version );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }
        if( version.compare("1.1") != 0 )
            throw FileReaderException("Wrong GEXF version.");
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for GEXF node.");
    }

}

//-----------------------------------------
void GexfParser::processMetaNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        const string lastmodifieddate = this->getStringAttribute(reader, "lastmodifieddate");
        _gexf->getMetaData().setLastModifiedDate( lastmodifieddate );
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Meta node.");
    }
}

//-----------------------------------------
void GexfParser::processCreatorNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int ret = xmlTextReaderRead(reader);
    if( ret == 1 ) {
        /* should be the text node */
        const xmlChar* const name = xmlTextReaderConstName(reader);
        if ( xmlStrEqual(name, xmlCharStrdup("#text")) == 1 ) {
            const int hasVal = xmlTextReaderHasValue(reader);
            if(hasVal == 1) {
                const xmlChar *value = xmlTextReaderConstValue(reader);
                if(value != NULL)
                    _gexf->getMetaData().setCreator( Conv::xmlCharToStr(value) );
            }
            else if(hasVal  == -1) {
                throw FileReaderException("An error occured in xmlTextReaderHasValue() for Creator node.");
            }
        }
    }
}

//-----------------------------------------
void GexfParser::processDescriptionNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int ret = xmlTextReaderRead(reader);
    if( ret == 1 ) {
        /* should be the text node */
        const xmlChar* const name = xmlTextReaderConstName(reader);
        if ( xmlStrEqual(name, xmlCharStrdup("#text")) == 1 ) {
            const int hasVal = xmlTextReaderHasValue(reader);
            if(hasVal == 1) {
                const xmlChar *value = xmlTextReaderConstValue(reader);
                if(value != NULL) {
                    _gexf->getMetaData().setDescription( Conv::xmlCharToStr(value) );
                }
            }
            else if(hasVal  == -1) {
                throw FileReaderException("An error occured in xmlTextReaderHasValue() for Description node.");
            }
        }
    }
}

//-----------------------------------------
void GexfParser::processGraphNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    _gexf->setGraphType(GRAPH_UNDIRECTED); /* default */
    
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        string mode = "static";
        try {
            mode = this->getStringAttribute(reader, "mode");
        } catch(exception &e) {
            cerr << "INFO " << "Unknown mode, static graph created by default." << endl;
        }
        if( mode.compare("dynamic") == 0 ) {
            // TODO implement dynamic mode
        }
        else { /* static used by default */
            // TODO activate the static mode
        }

        try {
            const string defaultedgetype = this->getStringAttribute(reader, "defaultedgetype");
            if( defaultedgetype.compare("directed") == 0 ) {
                _gexf->setGraphType(GRAPH_DIRECTED);
            }/* else if( defaultedgetype.compare("mixed") == 0 ) {
                _gexf->setGraphType(GRAPH_MIXED);
            }*/
            else {
                cerr << "INFO " << "Unknown default edge type, undirected used by default." << endl;
            }
        } catch (exception &e) {
            cerr << "INFO " << "Unknown default edge type, undirected used by default." << endl;
        }
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
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
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        const t_id node_id = this->getIdAttribute(reader, "id");
        const string label = this->getStringAttribute(reader, "label");

        _gexf->getUndirectedGraph().addNode( node_id );
        _gexf->getData().setLabel( node_id, label );
        _last_node_type = NODE;
        _last_id = node_id;
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
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
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        const t_id edge_id = this->getIdAttribute(reader, "id");
        const t_id source = this->getIdAttribute(reader, "source");
        const t_id target = this->getIdAttribute(reader, "target");
        unsigned int cardinal = 1;
        string tmp_type = "";
        try {
            cardinal = this->getUnsignedIntAttribute(reader, "cardinal");
        } catch(exception &e) {
            // nothing to do
        }
        try {
            tmp_type = this->getStringAttribute(reader, "type");
        } catch(exception &e) {
            // nothing to do
        }

        t_edge_type type = EDGE_UNDIRECTED;
        if( tmp_type.compare("double") == 0 ) {
            type = EDGE_DOUBLE;
        }
        else if( _gexf->getGraphType() == GRAPH_DIRECTED || tmp_type.compare("directed") == 0 ) {
            type = EDGE_DIRECTED;
        }

        if(_gexf->getGraphType() == GRAPH_DIRECTED) {
            _gexf->getDirectedGraph().addEdge( edge_id, source, target, cardinal, type);
        }
        else { /*undirected or mixed, use undirected*/
            _gexf->getUndirectedGraph().addEdge( edge_id, source, target, cardinal, type);
        }
        _last_node_type = EDGE;
        _last_id = edge_id;
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
    }
}

//-----------------------------------------
void GexfParser::processAttributesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        const string attribute_class = this->getStringAttribute(reader, "class");
        if( attribute_class.compare("node") == 0 ) {
            _last_node_type = ATTR_NODE;
        }
        else if( attribute_class.compare("edge") == 0 ) {
            _last_node_type = ATTR_EDGE;
        }
        else {
            throw FileReaderException("Attributes node: unknown class");
        }
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Attributes node.");
    }
}

//-----------------------------------------
void GexfParser::processAttributeNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        const t_id attribute_id = this->getIdAttribute(reader, "id");
        const string title = this->getStringAttribute(reader, "title");
        const string tmp_type = this->getStringAttribute(reader, "type");
        t_attr_type type = STRING; /* internal default value */

        if( tmp_type.compare("integer") == 0 )
            type = INTEGER;
        else if( tmp_type.compare("double") == 0 )
            type = DOUBLE;
        else if( tmp_type.compare("float") == 0 )
            type = FLOAT;
        else if( tmp_type.compare("boolean") == 0 )
            type = BOOLEAN;
        else if( tmp_type.compare("liststring") == 0 )
            type = LIST_STRING;

        if( _last_node_type == ATTR_NODE ) {
            _gexf->getData().addNodeAttributeColumn(attribute_id, title, type);
        }
        else if( _last_node_type == ATTR_EDGE ) {
            _gexf->getData().addEdgeAttributeColumn(attribute_id, title, type);
        }
        _last_id = attribute_id;
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
    }
}

//-----------------------------------------
void GexfParser::processAttributeDefaultNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int ret = xmlTextReaderRead(reader);
    if( ret == 1 ) {
        /* should be the text node */
        const xmlChar* const name = xmlTextReaderConstName(reader);
        if ( xmlStrEqual(name, xmlCharStrdup("#text")) == 1 ) {
            const int hasVal = xmlTextReaderHasValue(reader);
            if(hasVal == 1) {
                const xmlChar *value = xmlTextReaderConstValue(reader);
                if(value != NULL) {
                    if( _last_node_type == ATTR_NODE ) {
                        _gexf->getData().setNodeAttributeDefault(_last_id, Conv::xmlCharToStr(value));
                    }
                    else if( _last_node_type == ATTR_EDGE ) {
                        _gexf->getData().setEdgeAttributeDefault(_last_id, Conv::xmlCharToStr(value));
                    }
                }
            }
            else if(hasVal  == -1) {
                throw FileReaderException("An error occured in xmlTextReaderHasValue() for Default node.");
            }
        }
    }
}

//-----------------------------------------
void GexfParser::processAttributeOptionsNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const int ret = xmlTextReaderRead(reader);
    if( ret == 1 ) {
        /* should be the text node */
        const xmlChar* const name = xmlTextReaderConstName(reader);
        if ( xmlStrEqual(name, xmlCharStrdup("#text")) == 1 ) {
            const int hasVal = xmlTextReaderHasValue(reader);
            if(hasVal == 1) {
                const xmlChar *value = xmlTextReaderConstValue(reader);
                if(value != NULL) {
                    if( _last_node_type == ATTR_NODE ) {
                        _gexf->getData().setNodeAttributeOptions(_last_id, Conv::xmlCharToStr(value));
                    }
                    else if( _last_node_type == ATTR_EDGE ) {
                        _gexf->getData().setEdgeAttributeOptions(_last_id, Conv::xmlCharToStr(value));
                    }
                }
            }
            else if(hasVal  == -1) {
                throw FileReaderException("An error occured in xmlTextReaderHasValue() for Options node.");
            }
        }
    }
}

//-----------------------------------------
void GexfParser::processAttvaluesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    /* nothing to do */
}

//-----------------------------------------
void GexfParser::processAttvalueNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    const t_id attribute_id = this->getIdAttribute(reader, "for");
    const string value = this->getStringAttribute(reader, "value");

    if( _last_node_type == NODE ) {
        _gexf->getData().setNodeValue(_last_id, attribute_id, value);
    }
    else if( _last_node_type == EDGE ) {
        _gexf->getData().setEdgeValue(_last_id, attribute_id, value);
    }
}

//-----------------------------------------
bool GexfParser::isProcessableNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    /* for XmlNodeType, see http://www.gnu.org/software/dotgnu/pnetlib-doc/System/Xml/XmlNodeType.html
     */
    const int t = xmlTextReaderNodeType(reader);
    return t != 15 && t != 16 && t != 12 && t != 13 && t != 7;
}

//-----------------------------------------
t_id GexfParser::getIdAttribute(xmlTextReaderPtr reader, const char* const name) {
//-----------------------------------------
    const xmlChar* const attr = xmlTextReaderGetAttribute(reader, xmlCharStrdup(name));
    if( attr != NULL )
        return Conv::xmlCharToId(attr);
    else {
        stringstream ss;
        ss << "No attribute " << name;
        throw FileReaderException(ss.str());
    }
}

//-----------------------------------------
string GexfParser::getStringAttribute(xmlTextReaderPtr reader, const char* const name) {
//-----------------------------------------
    const xmlChar* const attr = xmlTextReaderGetAttribute(reader, xmlCharStrdup(name));
    if( attr != NULL )
        return Conv::xmlCharToStr(attr);
    else {
        stringstream ss;
        ss << "No attribute " << name;
        throw FileReaderException(ss.str());
    }
}

//-----------------------------------------
string GexfParser::getStringAttributeNs(xmlTextReaderPtr reader, const char* const name, const char* const namespaceURI) {
//-----------------------------------------
    const xmlChar* const attr = xmlTextReaderGetAttributeNs(reader, xmlCharStrdup(name), xmlCharStrdup(namespaceURI));
    if( attr != NULL )
        return Conv::xmlCharToStr(attr);
    else {
        stringstream ss;
        ss << "No attribute " << namespaceURI << ":" << name;
        throw FileReaderException(ss.str());
    }
}

//-----------------------------------------
unsigned int GexfParser::getUnsignedIntAttribute(xmlTextReaderPtr reader, const char* const name) {
//-----------------------------------------
    const xmlChar* const attr = xmlTextReaderGetAttribute(reader, xmlCharStrdup(name));
    if( attr != NULL )
        return Conv::xmlCharToUnsignedInt(attr);
    else {
        stringstream ss;
        ss << "No attribute " << name;
        throw FileReaderException(ss.str());
    }
}

} /* namespace libgexf */
