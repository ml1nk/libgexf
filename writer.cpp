/*! \file writer.cpp
   \author sebastien heymann
   \date 8 juillet 2009, 17:58
    \version 0.1
 */

#include "metadata.h"


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

#include "writer.h"
#include "exceptions.h"
#include "typedefs.h"

#include <string.h>
#include <sstream>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>


using namespace std;

namespace libgexf {

Writer::Writer(): _gexf(0), _filepath("") {
}

Writer::Writer(const string filepath, GEXF* gexf): _gexf(gexf),_filepath(filepath) {

}

Writer::Writer(const Writer& orig): _gexf(orig._gexf), _filepath(orig._filepath) {
}

Writer::~Writer() {
    // do not delete _gexf
}

//-----------------------------------------
GEXF Writer::getGEXFCopy() {
//-----------------------------------------
    GEXF gexf_copy(*_gexf);
    return gexf_copy;
}

//-----------------------------------------
void Writer::init(const string filepath, GEXF* gexf) {
//-----------------------------------------
    _filepath = filepath;
    _gexf = gexf;
}


//-----------------------------------------
void Writer::write() {
//-----------------------------------------
    #ifndef LIBXML_READER_ENABLED
    throw FileWriterException( "LIBXML NOT FOUND" );
    #endif

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    int rc;
    xmlTextWriterPtr writer;

    /* Create a new XmlWriter for _filepath, with no compression. */
    writer = xmlNewTextWriterFilename(_filepath.c_str(), 0);
    if (writer == NULL) {
        throw FileWriterException( "Error creating the xml writer" );
    }

    /* Start the document with the xml default for the version,
     * encoding _ENCODING and the default for the standalone
     * declaration. */
    rc = xmlTextWriterStartDocument(writer, NULL, _ENCODING, NULL);
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterStartDocument" );
    }

    this->writeGexfNode(writer);
    
    /* Here we could close the elements ORDER and EXAMPLE using the
     * function xmlTextWriterEndElement, but since we do not want to
     * write any other elements, we simply call xmlTextWriterEndDocument,
     * which will do all the work. */
    rc = xmlTextWriterEndDocument(writer);
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterEndDocument" );
    }

    /* Close file and free memory buffers */
    xmlFreeTextWriter(writer);
    xmlCleanupParser();
}

//-----------------------------------------
void Writer::writeGexfNode(xmlTextWriterPtr writer) {
//-----------------------------------------
int rc;

    /* Start an element named "gexf". Since thist is the first
     * element, this will be the root element of the document. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "gexf");
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterStartElement" );
    }

    /* Start an element named "xmlns" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "xmlns", BAD_CAST _gexf->getMetaData().getXmlns().c_str());
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterWriteAttribute");
    }

    /* Start an element named "xsi" */
    rc = xmlTextWriterWriteAttributeNS(writer, BAD_CAST "xmlns", BAD_CAST "xsi", NULL, BAD_CAST _gexf->getMetaData().getXsi().c_str());
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterWriteAttributeNS");
    }

    /* Start an element named "schemaLocation" */
    rc = xmlTextWriterWriteAttributeNS(writer, BAD_CAST "xmlns", BAD_CAST "schemaLocation", NULL, BAD_CAST _gexf->getMetaData().getSchema().c_str());
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterWriteAttributeNS");
    }

    /* Add an attribute with name "version" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "version", BAD_CAST _gexf->getMetaData().getVersion().c_str());
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    this->writeMetaNode(writer);

    this->writeGraphNode(writer);

    /* Close the element named gexf. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterEndElement" );
    }
}

//-----------------------------------------
void Writer::writeMetaNode(xmlTextWriterPtr writer) {
//-----------------------------------------
int rc;

    /* Start an element named "meta" as child of gexf. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "meta");
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    /* Start an element named "creator" */
    rc = xmlTextWriterWriteElement(writer, BAD_CAST "creator", BAD_CAST _gexf->getMetaData().getCreator().c_str());
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    /* Start an element named "description" */
    rc = xmlTextWriterWriteElement(writer, BAD_CAST "description", BAD_CAST _gexf->getMetaData().getDescription().c_str());
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    /* Start an element named "keywords" */
    rc = xmlTextWriterWriteElement(writer, BAD_CAST "keywords", BAD_CAST _gexf->getMetaData().getKeywords().c_str());
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    /* Close the element named meta. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterEndElement");
    }
}

//-----------------------------------------
void Writer::writeGraphNode(xmlTextWriterPtr writer) {
//-----------------------------------------
int rc;

    /* Start an element named "graph" as child of gexf. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "graph");
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    /* Add an attribute with name "mode" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "mode", BAD_CAST "static");
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    /* Add an attribute with name "defaultedgetype" */
    t_graph t = _gexf->getGraphType();
    if (t == GRAPH_DIRECTED) {
        rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "defaultedgetype", BAD_CAST "directed");
    }
    else if (t == GRAPH_UNDIRECTED) {
        rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "defaultedgetype", BAD_CAST "undirected");
    }
    else {
        rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "defaultedgetype", BAD_CAST "double");
    }
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    this->writeNodesNode(writer);

    this->writeEdgesNode(writer);

    /* Close the element named graph. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterEndElement");
    }
}



//-----------------------------------------
void Writer::writeNodesNode(xmlTextWriterPtr writer) {
//-----------------------------------------
int rc;

    /* Start an element named "nodes" as child of graph. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "nodes");
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    /* Iterate on each node */
    NodeIter* it = _gexf->getUndirectedGraph().getNodes();
    while(it->hasNext()) {
        t_id node_id = it->next();
        this->writeNodeNode(writer, this->unsignedIntToStr(node_id));
    }
    delete it;
    
    /* Close the element named nodes. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterEndElement");
    }
}

//-----------------------------------------
void Writer::writeNodeNode(xmlTextWriterPtr writer, const std::string node_id) {
//-----------------------------------------
int rc;

    /* Write an element named "node" as child of nodes. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "node");
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterWriteElement");
    }

    /* Add an attribute with name "id" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "id", BAD_CAST node_id.c_str());
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    /* Add an attribute with name "label" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "label", BAD_CAST "");
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    /* Close the element named node. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterEndElement");
    }
}

//-----------------------------------------
void Writer::writeEdgesNode(xmlTextWriterPtr writer) {
//-----------------------------------------
int rc;

    /* Start an element named "edges" as child of graph. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "edges");
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterStartElement");
    }

    //this->writeEdgeNode(writer);


    /* Iterate on each node */
    EdgeIter* it = _gexf->getUndirectedGraph().getEdges();
    while(it->hasNext()) {
        t_id edge_id = it->next();
        t_id source_id = it->currentSource();
        t_id target_id = it->currentTarget();
        this->writeEdgeNode(writer, this->unsignedIntToStr(edge_id), this->unsignedIntToStr(source_id), this->unsignedIntToStr(target_id));
    }
    delete it;

    /* Close the element named edges. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterEndElement");
    }
}

//-----------------------------------------
void Writer::writeEdgeNode(xmlTextWriterPtr writer, const std::string edge_id, const std::string source_id, const std::string target_id) {
//-----------------------------------------
int rc;

    /* Write an element named "edge" as child of edges. */
    rc = xmlTextWriterStartElement(writer, BAD_CAST "edge");
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterWriteElement");
    }

    /* Add an attribute with name "id" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "id", BAD_CAST edge_id.c_str());
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    /* Add an attribute with name "source" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "source", BAD_CAST source_id.c_str());
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    /* Add an attribute with name "target" */
    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "target", BAD_CAST target_id.c_str());
    if (rc < 0) {
        throw FileWriterException( "Error at xmlTextWriterWriteAttribute");
    }

    /* Close the element named edge. */
    rc = xmlTextWriterEndElement(writer);
    if (rc < 0) {
        throw FileWriterException("Error at xmlTextWriterEndElement");
    }
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
xmlChar* Writer::convertInput(const char *in, const char *encoding) const {
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
string Writer::unsignedIntToStr(const unsigned int i) {
//-----------------------------------------
    stringstream ss;
    ss << i;
    return ss.str();
}


} /* namespace libgexf */
