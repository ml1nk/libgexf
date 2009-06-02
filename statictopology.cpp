/* 
 * File:   statictopology.cpp
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

#include <set>


#include "statictopology.h"
#include "inserters.cpp"
#include <stdexcept>
#include <map>
using namespace std;

StaticTopology::StaticTopology() : _nodes(), _edges_source_target(), _edges_target_source() {
}

StaticTopology::StaticTopology(const StaticTopology& orig) {
}

StaticTopology::~StaticTopology() {
    _edges_source_target.clear();
    _edges_target_source.clear();
    _nodes.clear();
}

//-----------------------------------------
void StaticTopology::add_node(const unsigned long int id) {
//-----------------------------------------
    _nodes.insert(id);
}

//-----------------------------------------
void StaticTopology::remove_node(const unsigned long int id) {
//-----------------------------------------
    this->remove_in_edges(id);
    this->remove_out_edges(id);

    _nodes.erase(id);
}

//-----------------------------------------
void StaticTopology::add_edge(const unsigned long int id, const unsigned long int source_id, const unsigned long int target_id) {
//-----------------------------------------
map<unsigned long int,map<unsigned long int,unsigned long int> >::iterator it;
map<unsigned long int,set<unsigned long int> >::iterator it2;

    // 2 * O(log-n)
    if( _nodes.find(source_id) == _nodes.end() ) {
        throw invalid_argument("No source node");
    }
    if( _nodes.find(target_id) == _nodes.end() ) {
        throw invalid_argument("No target node");
    }

    // 2*O(log-n)
    it = _edges_source_target.find(source_id);
    if(it != _edges_source_target.end()) {
        pair<unsigned long int,unsigned long int> link = pair<unsigned long int,unsigned long int>(target_id,id);
        ((*it).second).insert(link);
    }
    else {
        map<unsigned long int,unsigned long int> edges;
        edges.insert(pair<unsigned long int,unsigned long int>(target_id,id));
        _edges_source_target.insert(pair<unsigned long int,map<unsigned long int,unsigned long int> >(source_id, edges));
    }

    it2 = _edges_target_source.find(target_id);
    if(it2 != _edges_target_source.end()) {
        ((*it2).second).insert(source_id);
    }
    else {
        set<unsigned long int> edges;
        edges.insert(source_id);
        _edges_target_source.insert(pair<unsigned long int,set<unsigned long int> >(target_id,edges));
    }
}

//-----------------------------------------
void StaticTopology::remove_edge(const unsigned long int source_id, const unsigned long int target_id) {
//-----------------------------------------
    // O(log-n)
    map<unsigned long int,unsigned long int>& link = _edges_source_target[source_id];
    link.erase(target_id);
    if(link.empty()) {
        _edges_source_target.erase(source_id);
    }

    // O(log-n)
    set<unsigned long int>& sources = _edges_target_source[target_id];
    sources.erase(source_id);
    if(sources.empty()) {
        _edges_target_source.erase(target_id);
    }
}

//-----------------------------------------
void StaticTopology::remove_in_edges(const unsigned long int target_id) {
//-----------------------------------------
set<unsigned long int>::iterator it_source_id;

    // O(n + 4*log-n)
    set<unsigned long int>& sources = _edges_target_source[target_id];
    for ( it_source_id=sources.begin() ; it_source_id != sources.end(); it_source_id++ ) {
        _edges_source_target[*it_source_id].erase(target_id);
    }
    _edges_target_source.erase(target_id);
}

//-----------------------------------------
void StaticTopology::remove_out_edges(const unsigned long int source_id) {
//-----------------------------------------
map<unsigned long int,unsigned long int>::iterator it_target;

    // O(n + 4*log-n)
    map<unsigned long int,unsigned long int>& link = _edges_source_target[source_id];
    for ( it_target=link.begin() ; it_target != link.end(); it_target++ ) {
        _edges_target_source[(*it_target).first].erase(source_id);
    }
    _edges_source_target.erase(source_id);
}

//-----------------------------------------
unsigned long int StaticTopology::num_nodes() {
//-----------------------------------------
    return _nodes.size();
}

//-----------------------------------------
unsigned long int StaticTopology::num_edges() {
//-----------------------------------------
    return _edges_source_target.size();
}


//-----------------------------------------
ostream& operator<<(ostream& os, const StaticTopology& o) {
//-----------------------------------------
    os << "  " << "StaticTopology [" << endl;
    os << "    _nodes [" << endl;
    os << "    " << o._nodes << "    ]" << endl;
    os << "    _edges_source_target [" << endl;
    os << "    " << o._edges_source_target << "    ]" << endl;
    os << "    _edges_target_source [" << endl;
    os << "    " << o._edges_target_source << "    ]" << endl;
    return os;
}

