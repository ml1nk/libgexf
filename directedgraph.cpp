/*! \file directedgraph.cpp
    \author sebastien heymann
    \date 8 juin 2009, 10:21
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

#include "directedgraph.h"
#include "exceptions.h"
#include <stdexcept>
#include <map>
#include <set>
using namespace std;

namespace libgexf {

DirectedGraph::DirectedGraph() : Graph() {
}

DirectedGraph::DirectedGraph(const DirectedGraph& orig) : Graph(orig) {
}

DirectedGraph::~DirectedGraph() {
}

//-----------------------------------------
std::set<t_id> DirectedGraph::getInEdges(const t_id node_id) const {
//-----------------------------------------
set<t_id> s = set<t_id>();

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(2n)
    map<t_id,set<t_id> >::const_iterator it_re = _reverse_edges.find(node_id);
    if(it_re != _reverse_edges.end()) {
        for(set<t_id>::const_iterator it = (it_re->second).begin(); it != (it_re->second).end(); it++) {
            t_id source_id = *it;
            map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(source_id);
            if(it_e != _edges.end()) {
                for(map<t_id,t_id>::const_iterator it2 = (it_e->second).begin(); it2 != (it_e->second).end(); it2++) {
                    t_id edge_id = it2->second;
                    s.insert(edge_id);
                }
            }
        }
    }

    return s;
}

//-----------------------------------------
std::set<t_id> DirectedGraph::getOutEdges(const t_id node_id) const {
//-----------------------------------------
set<t_id> s = set<t_id>();

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(2n)
    map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(node_id);
    if(it_e != _edges.end()) {
        for(map<t_id,t_id>::const_iterator it2 = (it_e->second).begin(); it2 != (it_e->second).end(); it2++) {
            t_id edge_id = it2->second;
            s.insert(edge_id);
        }
    }
    else {
        throw invalid_argument(MessageExceptionBuilder::buildString("Invalid node", node_id));
    }

    return s;
}

//-----------------------------------------
std::set<t_id> DirectedGraph::getSuccessors(const t_id node_id) const {
//-----------------------------------------
set<t_id> s = set<t_id>();

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(node_id);
    if(it_e != _edges.end()) {
        // 0(n)
        for(map<t_id,t_id>::const_iterator it = (it_e->second).begin(); it != (it_e->second).end(); it++) {
            t_id succ_id = it->first;
            s.insert(succ_id);
        }
    }

    return s;
}

//-----------------------------------------
std::set<t_id> DirectedGraph::getPredecessors(const t_id node_id) const {
//-----------------------------------------
set<t_id> s = set<t_id>();

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(n)
    map<t_id,set<t_id> >::const_iterator it_re = _reverse_edges.find(node_id);
    if(it_re != _reverse_edges.end()) {
        for(set<t_id>::const_iterator it = (it_re->second).begin(); it != (it_re->second).end(); it++) {
            t_id pred_id = *it;
            s.insert(pred_id);
        }
    }

    return s;
}

//-----------------------------------------
unsigned int DirectedGraph::getInDegree(const t_id node_id) const {
//-----------------------------------------
unsigned int count = 0;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(log-n)
    map<t_id,set<t_id> >::const_iterator it_re = _reverse_edges.find(node_id);
    if(it_re != _reverse_edges.end()) {
        count += (it_re->second).size();
    }


    return count;
}

//-----------------------------------------
unsigned int DirectedGraph::getOutDegree(const t_id node_id) const {
//-----------------------------------------
unsigned int count = 0;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(log-n)
    map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(node_id);
    if(it_e != _edges.end()) {
        count += (it_e->second).size();
    }

    return count;
}

//-----------------------------------------
bool DirectedGraph::isSuccessor(const t_id node_id, const t_id successor_id) const {
//-----------------------------------------
bool is = false;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(log-n)
    map<t_id,map<t_id,t_id> >::const_iterator it_e = _edges.find(node_id);
    if(it_e != _edges.end()) {
        is = ( (it_e->second).find(successor_id) != (it_e->second).end() );
    }

return is;
}

//-----------------------------------------
bool DirectedGraph::isPredecessor(const t_id node_id, const t_id predecessor_id) const {
//-----------------------------------------
bool is = false;

    if(_lock_flag == '2') throw WriteLockException("Read not allowed");

    // 0(log-n)
    map<t_id,set<t_id> >::const_iterator it_re = _reverse_edges.find(node_id);
    if(it_re != _reverse_edges.end()) {
        is = ( (it_re->second).find(predecessor_id) != (it_re->second).end() );
    }

return is;
}


}
