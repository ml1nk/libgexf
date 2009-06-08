/*! \file directedgraph.h
    \author sebastien heymann
    \date 8 juin 2009, 10:21
    \version 0.1
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

