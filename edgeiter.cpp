/* 
 * File:   edgeiter.cpp
 * Author: sebastien
 * 
 * Created on 9 juillet 2009, 17:38
 */

#include <map>


#include "edgeiter.h"

using namespace std;

namespace libgexf {

EdgeIter::EdgeIter(const Graph* g): _graph(g), _cpt(0), _nb_items(g->getInternalEdgeCount()) {
    this->begin();
}

EdgeIter::~EdgeIter() {
}

EdgeIter* EdgeIter::begin() {
    _it = _graph->_edges.begin();
    _it2 = _it->second.begin();
    return this;
}

bool EdgeIter::hasNext() const {
    return _nb_items != 0 && _cpt != _nb_items;
}

t_id EdgeIter::next() {
    t_id edge_id = _it2->second;
    _current_source = _it->first;
    _current_target = _it2->first;

    _cpt++;
    _it2++;
    if(_it2 == _it->second.end()) {
        _it++;
        _it2 = _it->second.begin();
    }

    return edge_id;
}

t_id EdgeIter::currentSource() const {
    return _current_source;
}

t_id EdgeIter::currentTarget() const {
    return _current_target;
}

float EdgeIter::currentProperty(t_edge_property prop) const {
    float r = 0.0;
    t_id edge_id = _it2->second;
    map<t_id,std::map<t_edge_property,t_edge_value> >::const_iterator it_properties = _graph->_edges_properties.find(edge_id);
    if( it_properties != _graph->_edges_properties.end() ) {
        map<t_edge_property,t_edge_value>::const_iterator it_prop = (it_properties->second).find(prop);
        if( it_prop != (it_properties->second).end() ) {
            r = it_prop->second;
        }
    }
    return r;
}

}
