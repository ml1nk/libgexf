/* 
 * File:   edgeiter.cpp
 * Author: sebastien
 * 
 * Created on 9 juillet 2009, 17:38
 */

#include "edgeiter.h"

using namespace std;

namespace libgexf {

EdgeIter::EdgeIter(const Graph* g): _graph(g), _cpt(0), _nb_items(g->getEdgeCount()) {
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
    return _cpt != _graph->getEdgeCount();
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

}
