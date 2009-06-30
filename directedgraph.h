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

    std::set<t_id> getInEdges(const t_id node_id) const;
    std::set<t_id> getOutEdges(const t_id node_id) const;
    std::set<t_id> getSuccessors(const t_id node_id) const;
    std::set<t_id> getPredecessors(const t_id node_id) const;

    unsigned int getInDegree(const t_id node_id) const;
    unsigned int getOutDegree(const t_id node_id) const;

    bool isSuccessor(const t_id node_id, const t_id successor_id) const;
    bool isPredecessor(const t_id node_id, const t_id predecessor_id) const;
private:
    DirectedGraph& operator=(const DirectedGraph& orig);
};

}

#endif	/* _DIRECTEDGRAPH_H */

