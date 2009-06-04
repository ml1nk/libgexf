/* 
 * File:   graph.cpp
 * Author: sebastien heymann
 * 
 * Created on 17 avril 2009, 17:27
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

#include "graph.h"
#include "graph_exceptions.h"
#include "inserters.cpp"
#include <stdexcept>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

Graph::Graph() : _nodes(), _edges(), _reverse_edges(), _bloom_edges() {
     _lock_flag = '0';
     _rlock_count = 0;
}

Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
    _edges.clear();
    _reverse_edges.clear();
    _bloom_edges.clear();
    _nodes.clear();
}

//-----------------------------------------
void Graph::addNode(const t_id id) {
//-----------------------------------------
    if(_lock_flag == '1') throw ReadLockException("Write not allowed");
    _nodes.insert(id);
}

//-----------------------------------------
void Graph::addEdge(const t_id id, const t_id source_id, const t_id target_id) {
//-----------------------------------------
map<t_id,map<t_id,t_id> >::iterator it;
map<t_id,set<t_id> >::iterator it2;

    if(_lock_flag == '1') throw ReadLockException("Write not allowed");

    if(_bloom_edges.find(id) != _bloom_edges.end()) {
        ostringstream ostr;
        ostr << id;
        throw invalid_argument("Edge id already in bloom filter: " + ostr.str());
    }

    // 2 * O(log-n)
    if( _nodes.find(source_id) == _nodes.end() ) {
        throw invalid_argument("No source node");
    }
    if( _nodes.find(target_id) == _nodes.end() ) {
        throw invalid_argument("No target node");
    }

    // 2*O(log-n)
    it = _edges.find(source_id);
    if(it != _edges.end()) {
        pair<t_id,t_id> link = pair<t_id,t_id>(target_id,id);
        ((*it).second).insert(link);
    }
    else {
        map<t_id,t_id> edges;
        edges.insert(pair<t_id,t_id>(target_id,id));
        _edges.insert(pair<t_id,map<t_id,t_id> >(source_id, edges));
    }

    // 2*O(log-n)
    it2 = _reverse_edges.find(target_id);
    if(it2 != _reverse_edges.end()) {
        ((*it2).second).insert(source_id);
    }
    else {
        set<t_id> edges;
        edges.insert(source_id);
        _reverse_edges.insert(pair<t_id,set<t_id> >(target_id,edges));
    }

    _bloom_edges.insert(id);
}

//-----------------------------------------
void Graph::removeNode(const t_id id) {
//-----------------------------------------
    if(_lock_flag == '1') throw ReadLockException("Write not allowed");

    // 0(2n)
    this->clearEdges(id);

    // O(log-n)
    _nodes.erase(id);
}

//-----------------------------------------
void Graph::removeEdge(const t_id source_id, const t_id target_id) {
//-----------------------------------------
map<t_id,t_id>::const_iterator it;

    if(_lock_flag == '1') throw ReadLockException("Write not allowed");

    // O(log-n)
    map<t_id,t_id>& links = _edges[source_id];
    for( it=links.begin() ; it != links.end(); it++ ) {
        _bloom_edges.erase(it->second);
    }
    links.erase(target_id);
    if(links.empty()) {
        _edges.erase(source_id);
    }

    // O(log-n)
    set<t_id>& sources = _reverse_edges[target_id];
    sources.erase(source_id);
    if(sources.empty()) {
        _reverse_edges.erase(target_id);
    }
}

//-----------------------------------------
void Graph::removeInEdges(const t_id target_id) {
//-----------------------------------------
set<t_id>::iterator it;
map<t_id,t_id>::const_iterator it2;

    if(_lock_flag == '1') throw ReadLockException("Write not allowed");

    // O(n + 4*log-n)
    set<t_id>& sources = _reverse_edges[target_id];
    for( it=sources.begin() ; it != sources.end(); it++ ) {
        for( it2=_edges[*it].begin() ; it2 != _edges[*it].end(); it2++ ) {
            _bloom_edges.erase(it2->second);
        }
        _edges[*it].erase(target_id);
        if(_edges[*it].empty()) {
            _edges.erase(*it);
        }
    }
    _reverse_edges.erase(target_id);
}

//-----------------------------------------
void Graph::removeOutEdges(const t_id source_id) {
//-----------------------------------------
map<t_id,t_id>::iterator it;
map<t_id,t_id>::const_iterator it2;

    if(_lock_flag == '1') throw ReadLockException("Write not allowed");

    // O(n + 4*log-n)
    map<t_id,t_id>& links = _edges[source_id];
    for( it=links.begin() ; it != links.end(); it++ ) {
        _bloom_edges.erase(it->second);
        _reverse_edges[it->first].erase(source_id);
        if(_reverse_edges[it->first].empty()) {
            _reverse_edges.erase(it->first);
        }
    }
    _edges.erase(source_id);
}

//-----------------------------------------
bool Graph::containsNode(const t_id id) const {
//-----------------------------------------
    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(log-n)
    return (_nodes.find(id) != _nodes.end());
}

//-----------------------------------------
bool Graph::containsEdge(const t_id source_id, const t_id target_id) const {
//-----------------------------------------
bool exist = false;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 2*0(log-n)
    map<t_id,map<t_id,t_id> >::const_iterator it = _edges.find(source_id);
    if(it != _edges.end()) {
        exist = ((it->second).find(target_id) != (it->second).end());
    }
    return exist;
}

//-----------------------------------------
unsigned int Graph::getNodeCount() const {
//-----------------------------------------
    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    return _nodes.size();
}

//-----------------------------------------
unsigned int Graph::getEdgeCount() const {
//-----------------------------------------
unsigned int count = 0;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    for(map<t_id,map<t_id,t_id> >::const_iterator it = _edges.begin() ; it != _edges.end() ; it++) {
        count += (it->second).size();
    }

    return count;
}

//-----------------------------------------
unsigned int Graph::getDegree(const t_id node_id) const {
//-----------------------------------------
unsigned int count = 0;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(log-n)
    map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(node_id);
    if(it_e != _edges.end()) {
        count += (it_e->second).size();
    }

    // 0(log-n)
    map<t_id,set<t_id> >::const_iterator it_re = _reverse_edges.find(node_id);
    if(it_re != _reverse_edges.end()) {
        count += (it_re->second).size();
    }

    return count;
}

//-----------------------------------------
set<t_id> Graph::getNeighbors(const t_id node_id) const {
//-----------------------------------------
set<t_id> s;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(node_id);
    if(it_e != _edges.end()) {
        // 0(n)
        for(map<t_id,t_id>::const_iterator it = (it_e->second).begin(); it != (it_e->second).end(); it++) {
            t_id i = it->first;
            s.insert(i);
        }
        // 0(n)
        map<t_id,set<t_id> >::const_iterator it_re = _reverse_edges.find(node_id);
        if(it_re != _reverse_edges.end()) {
            for(set<t_id>::const_iterator it = (it_re->second).begin(); it != (it_re->second).end(); it++) {
                t_id i = *it;
                s.insert(i);
            }
        }
    }

    return s;
}

//-----------------------------------------
void Graph::clearEdges(const t_id node_id) {
//-----------------------------------------
    if(_lock_flag == '1') throw ReadLockException("Write not allowed");

    // 0(2n)
    this->removeInEdges(node_id);
    this->removeOutEdges(node_id);
}

//-----------------------------------------
void Graph::clear() {
//-----------------------------------------
    if(_lock_flag == '1') throw ReadLockException("Write not allowed");
    _edges.clear();
    _reverse_edges.clear();
    _bloom_edges.clear();
    _nodes.clear();
     _lock_flag = '0';
}

//-----------------------------------------
void Graph::clearEdges() {
//-----------------------------------------
    if(_lock_flag == '1') throw ReadLockException("Write not allowed");
    _edges.clear();
    _reverse_edges.clear();
    _bloom_edges.clear();
}

//-----------------------------------------
void Graph::readLock() throw() {
//-----------------------------------------
    if(_lock_flag != '2') {
        _lock_flag = '1';
        _rlock_count +=1;
    }
    else throw ReadLockException("Can't set a read-lock: a write-lock exists");
}

//-----------------------------------------
void Graph::readUnlock() {
//-----------------------------------------
    if(_rlock_count >= 1) {
        _rlock_count -=1;
        if(_rlock_count == 0) _lock_flag = '0';
    }
}

//-----------------------------------------
void Graph::writeLock() throw() {
//-----------------------------------------
    if(_lock_flag == '0')  _lock_flag = '2';
    else throw WriteLockException("Can't set a write-lock: another lock exists");
}

//-----------------------------------------
void Graph::writeUnlock() {
//-----------------------------------------
    _lock_flag = '0';
}

//-----------------------------------------
bool Graph::isReadLock() {
//-----------------------------------------
    return _lock_flag == '1';
}

//-----------------------------------------
bool Graph::isWriteLock() {
//-----------------------------------------
    return _lock_flag == '2';
}

//-----------------------------------------
bool Graph::isUnlock() {
//-----------------------------------------
    return _lock_flag == '0';
}


//-----------------------------------------
ostream& operator<<(ostream& os, const Graph& o) {
//-----------------------------------------
    os << "Graph [" << endl;
    os << "_nodes [" << endl;
    os << o._nodes << "]" << endl << endl;
    os << "_edges [" << endl;
    os << o._edges << "]" << endl << endl;
    os << "_reverse_edges [" << endl;
    os << o._reverse_edges << "]" << endl << endl;
    return os;
}

