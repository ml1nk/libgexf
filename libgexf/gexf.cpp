/*! \file gexf.cpp
    \author sebastien heymann
    \date 17 avril 2009, 17:28
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

#include "gexf.h"
#include "data.h"
#include "conv.h"

#include <cstdio>
#include <string>

namespace libgexf {

GEXF::GEXF(): _graph(), _type(GRAPH_MIXED), _data(), _meta() {
}

GEXF::GEXF(const GEXF& orig) : _graph(orig._graph), _type(orig._type), _data(orig._data), _meta(orig._meta) {
}

GEXF::~GEXF() {
}

//-----------------------------------------
UndirectedGraph& GEXF::getUndirectedGraph() {
//-----------------------------------------
    // a graph is instanciable if the current one is empty
    if(_graph.getNodeCount() == 0) {
        UndirectedGraph* g = new UndirectedGraph();
        _graph = *g;
        _type = GRAPH_UNDIRECTED;
    }

    return (UndirectedGraph&)_graph;
}

//-----------------------------------------
DirectedGraph& GEXF::getDirectedGraph() {
//-----------------------------------------
    // a graph is instanciable if the current one is empty
    if(_graph.getNodeCount() == 0) {
        DirectedGraph* g = new DirectedGraph();
        _graph = *g;
        _type = GRAPH_DIRECTED;
    }

    return (DirectedGraph&)_graph;
}

//-----------------------------------------
t_graph GEXF::getGraphType() {
//-----------------------------------------
    return _type;
}

//-----------------------------------------
void GEXF::setGraphType(t_graph t) {
//-----------------------------------------
    _type = t;
}

//-----------------------------------------
Data& GEXF::getData() {
//-----------------------------------------
    return _data;
}

//-----------------------------------------
MetaData& GEXF::getMetaData() {
//-----------------------------------------
    return _meta;
}

//-----------------------------------------
bool GEXF::checkIntegrity() {
//-----------------------------------------
    return ( checkNodeLabels() && checkAttValues() );
}

//-----------------------------------------
bool GEXF::checkNodeLabels() const {
//-----------------------------------------
bool r = true;

    /* check if each node has a label */
    NodeIter* it = _graph.getNodes();
    while(it->hasNext()) {
        const t_id node_id = it->next();
        if( !_data.hasLabel(node_id) )
            std::cerr << "No label for the node " << (std::string)node_id << std::endl;
    }

    return r;
}

//-----------------------------------------
bool GEXF::checkAttValues() const {
//-----------------------------------------
bool r = true;

    /* check if each attvalue has a value or a defaultvalue, and the type of each value */
    AttributeIter* it_attr = _data.getNodeAttributeColumn();
    while(it_attr->hasNext()) {
        const t_id attr_id = it_attr->next();
        const std::string title = it_attr->currentTitle();
        const t_attr_type type = it_attr->currentType();
        const bool has_default = _data.hasNodeAttributeDefault(attr_id);
        NodeIter* it_node = _graph.getNodes();
        while(it_node->hasNext()) {
            const t_id node_id = it_node->next();
            const std::string value = _data.getNodeAttribute(node_id, attr_id);
            if( value.empty() ) {
                if( !has_default ) {
                    r = false;
                    std::cerr << "A value is required for the attribute " << title << "(id=" << (std::string)attr_id << ") of the node " << (std::string)node_id << std::endl;
                }
            }
            else {
                r = r && checkAttValueType(value, type, node_id, attr_id, true);
            }
        }
    }
    it_attr = _data.getEdgeAttributeColumn();
    while(it_attr->hasNext()) {
        const t_id attr_id = it_attr->next();
        const std::string title = it_attr->currentTitle();
        const t_attr_type type = it_attr->currentType();
        const bool has_default = _data.hasEdgeAttributeDefault(attr_id);
        EdgeIter* it_edge = _graph.getEdges();
        while(it_edge->hasNext()) {
            const t_id edge_id = it_edge->next();
            const std::string value = _data.getNodeAttribute(edge_id, attr_id);
            if( value.empty() ) {
                if( !has_default ) {
                    r = false;
                    std::cerr << "A value is required for the attribute " << title << "(id=" << (std::string)attr_id << ") of the edge " << (std::string)edge_id << std::endl;
                }
            }
            else {
                r = r && checkAttValueType(value, type, edge_id, attr_id, false);
            }
        }
    }

    return r;
}

//-----------------------------------------
bool GEXF::checkAttValueType(const std::string& value, const libgexf::t_attr_type type, const t_id elem_id, const t_id attr_id, const bool isNode) const {
//-----------------------------------------
bool r = false;

    switch(type) {
        case INTEGER:
            r = Conv::isInteger(value);
            if( !r ) {
                const std::string elem = (isNode) ? "node" : "edge";
                std::cerr << "Attribute type error for the " << elem << " \"" << elem_id << "\": \"" << value << "\" should be an integer" << std::endl;
            }
            break;
        case DOUBLE:
            r = Conv::isDouble(value);
            if( !r ) {
                const std::string elem = (isNode) ? "node" : "edge";
                std::cerr << "Attribute type error for the " << elem << " \"" << elem_id << "\": \"" << value << "\" should be a double" << std::endl;
            }
            break;
        case FLOAT:
            r = Conv::isFloat(value);
            if( !r ) {
                const std::string elem = (isNode) ? "node" : "edge";
                std::cerr << "Attribute type error for the " << elem << " \"" << elem_id << "\": \"" << value << "\" should be a float" << std::endl;
            }
            break;
        case BOOLEAN:
            r = Conv::isBoolean(value);
            if( !r ) {
                const std::string elem = (isNode) ? "node" : "edge";
                std::cerr << "Attribute type error for the " << elem << " \"" << elem_id << "\": \"" << value << "\" should be a boolean (true|false)" << std::endl;
            }
            break;
        case LIST_STRING:
            if( isNode ) {
                r = _data.isNodeAttributeOption(attr_id, value);
            }
            else {
                r = _data.isEdgeAttributeOption(attr_id, value);
            }
            if( !r ) {
                const std::string elem = (isNode) ? "node" : "edge";
                std::cerr << "Attribute type error for the " << elem << " \"" << elem_id << "\": \"" << value << "\" does not exist in option \"" << attr_id << "\"" << std::endl;
            }
            break;
        default: // =STRING
            r = true;
            break;
    }

    return r;
}

//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const GEXF& o) {
//-----------------------------------------
    os << "GEXF [" << std::endl;
    os << o._graph << std::endl;
    os << o._meta << std::endl;
    os << o._data << "]" << std::endl;
    return os;
}


} /* namespace libgexf */
