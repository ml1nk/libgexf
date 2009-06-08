/*! \file undirectedgraph.cpp
    \author sebastien heymann
    \date 8 juin 2009, 10:21
    \version 0.1
 */

#include "undirectedgraph.h"

namespace libgexf {

UndirectedGraph::UndirectedGraph() : Graph() {
}

UndirectedGraph::UndirectedGraph(const UndirectedGraph& orig) : Graph(orig) {
}

UndirectedGraph::~UndirectedGraph() {
}

}
