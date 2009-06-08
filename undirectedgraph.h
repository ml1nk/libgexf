/*! \file undirectedgraph.h
    \author sebastien heymann
    \date 8 juin 2009, 10:21
    \version 0.1
 */

#ifndef _UNDIRECTEDGRAPH_H
#define	_UNDIRECTEDGRAPH_H

#include "graph.h"

namespace libgexf {

class UndirectedGraph: public Graph {
public:
    UndirectedGraph();
    UndirectedGraph(const UndirectedGraph& orig);
    virtual ~UndirectedGraph();
private:
    UndirectedGraph& operator=(const UndirectedGraph& orig);
};

}

#endif	/* _UNDIRECTEDGRAPH_H */

