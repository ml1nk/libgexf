/*! \file graph.h
    \author sebastien heymann
    \date 17 avril 2009, 17:27
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

#ifndef _GRAPH_H
#define	_GRAPH_H

#include <set>
#include <map>
#include <iostream>
#include "typedefs.h"
#include "exceptions.h"
#include "nodeiter.h"
#include "edgeiter.h"

namespace libgexf {

class NodeIter;
class EdgeIter;

/*! \class Graph
    \brief Topology structure of the graph
 */
class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();

    void addNode(const libgexf::t_id id);
    void addEdge(const libgexf::t_id id, const libgexf::t_id source_id, const libgexf::t_id target_id, const unsigned int cardinal=1, const libgexf::t_edge_type type=EDGE_UNDEF);
    void removeNode(const libgexf::t_id id);
    void removeEdge(const libgexf::t_id source_id, const libgexf::t_id target_id);

    bool containsNode(const libgexf::t_id id) const;
    bool containsEdge(const libgexf::t_id source_id, const libgexf::t_id target_id) const;

    libgexf::NodeIter* getNodes() const;
    libgexf::EdgeIter* getEdges() const;
    std::set<libgexf::t_id> getNeighbors(const libgexf::t_id node_id) const;

    unsigned int getNodeCount() const;
    unsigned int getEdgeCount() const;
    unsigned int getDegree(const libgexf::t_id node_id) const;

    void clearEdges(const libgexf::t_id node_id);
    void clear();
    void clearEdges();
    
    void readLock() throw(libgexf::ReadLockException);
    void readUnlock();
    void writeLock() throw(libgexf::WriteLockException);
    void writeUnlock();
    bool isReadLock();
    bool isWriteLock();
    bool isUnlock();
protected:
    std::set<t_id> _nodes; /*!< Set of all nodes */
    std::map<t_id,std::map<t_id,t_id> > _edges; /*!< map<source_id, map<target_id, edge_id> > */
    std::map<t_id,std::set<t_id> > _reverse_edges; /*!< map<target_id, set<source_id> > */
    std::set<t_id> _bloom_edges; /*!< Set of all edge_id used as a (poor) bloom filter */
    std::map<t_id,std::map<t_edge_property,t_edge_value> > _edges_properties; /*!<Topological properties of edges */
    unsigned short int _rlock_count; /*!< Number of read-locks */
    /*! \var char _lock_flag
        \brief Flag used for determining the lock type:
        \li 0 = unlocked
        \li 1 = read locked
        \li 2 = write locked
     */
    char _lock_flag;

    unsigned int getInternalEdgeCount() const; /*!< Used for EdgeIter > */

    friend std::ostream& operator<<(std::ostream& os, const Graph& o);
    friend class NodeIter;
    friend class EdgeIter;
private:
    //Graph& operator=(const Graph& orig);
};

} /* namespace libgexf */

#endif	/* _GRAPH_H */

