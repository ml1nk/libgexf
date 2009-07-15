/* 
 * File:   attributeiter.cpp
 * Author: sebastien
 * 
 * Created on 15 juillet 2009, 14:27
 */

#include "attributeiter.h"

using namespace std;

namespace libgexf {

AttributeIter::AttributeIter(const Data* d, AttributeIter::Type t): _data(d), _t(t), _cpt(0), _nb_items(0) {
    this->begin();
}

AttributeIter::~AttributeIter() {
}

AttributeIter* AttributeIter::begin() {
    if( _t == NODE ) {
        _it = _data->_node_attributes.begin();
        _nb_items = _data->countNodeAttributeColumn();
    }
    else if( _t == EDGE ) {
        _it = _data->_edge_attributes.begin();
        _nb_items = _data->countEdgeAttributeColumn();
    }
    return this;
}

bool AttributeIter::hasNext() const {
    return _nb_items != 0 && _cpt != _nb_items;
}

t_id AttributeIter::next() {
    if( _cpt != 0 &&
        (_t == NODE && _it != _data->_node_attributes.end()) ||
        (_t == EDGE && _it != _data->_edge_attributes.end()) ) {
        _it++;
    }
    _cpt++;
    return _it->first;
}

string AttributeIter::currentTitle() const {
    return _it->second;
}

t_attr_type AttributeIter::currentType() const {
    if( _t == NODE ) {
        std::map<t_id,t_attr_type >::const_iterator it2 = _data->_node_attributes_types.find(_it->first);
        if( it2 != _data->_node_attributes_types.end() ) {
            return it2->second;
        }
    }
    else if( _t == EDGE ) {
        std::map<t_id,t_attr_type >::const_iterator it2 = _data->_edge_attributes_types.find(_it->first);
        if( it2 != _data->_edge_attributes_types.end() ) {
            return it2->second;
        }
    }

    return STRING;
}

}
