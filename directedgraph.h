/*! \file directedgraph.h
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

#ifndef _DIRECTEDGRAPH_H
#define	_DIRECTEDGRAPH_H

#include "graph.h"

namespace libgexf {

class DirectedGraph: public Graph {
public:
    DirectedGraph();
    DirectedGraph(const DirectedGraph& orig);
    virtual ~DirectedGraph();

    void removeInEdges(const libgexf::t_id target_id);
    void removeOutEdges(const libgexf::t_id source_id);

    std::set<libgexf::t_id> getInEdges(const libgexf::t_id node_id) const;
    std::set<libgexf::t_id> getOutEdges(const libgexf::t_id node_id) const;
    std::set<libgexf::t_id> getSuccessors(const libgexf::t_id node_id) const;
    std::set<libgexf::t_id> getPredecessors(const libgexf::t_id node_id) const;

    unsigned int getInDegree(const libgexf::t_id node_id) const;
    unsigned int getOutDegree(const libgexf::t_id node_id) const;

    bool isSuccessor(const libgexf::t_id node_id, const libgexf::t_id successor_id) const;
    bool isPredecessor(const libgexf::t_id node_id, const libgexf::t_id predecessor_id) const;
private:
    DirectedGraph& operator=(const DirectedGraph& orig);
};

}

#endif	/* _DIRECTEDGRAPH_H */

