/* 
 * File:   graph.h
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

#ifndef _GRAPH_H
#define	_GRAPH_H

#include <set>
#include <map>
#include <iostream>
using namespace std;

typedef unsigned int t_id;

class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();

    void addNode(const t_id id);
    void addEdge(const t_id id, const t_id source_id, const t_id target_id);
    void removeNode(const t_id id);
    void removeEdge(const t_id source_id, const t_id target_id);
    void removeInEdges(const t_id target_id);
    void removeOutEdges(const t_id source_id);

    bool containsNode(const t_id id) const;
    bool containsEdge(const t_id source_id, const t_id target_id) const;

    unsigned int getNodeCount() const;
    unsigned int getEdgeCount() const;
    unsigned int getDegree(const t_id node_id) const;
    set<t_id> getNeighbors(const t_id node_id) const;

    void clearEdges(const t_id node_id);
    void clear();
    void clearEdges();
    
    void readLock() throw();
    void readUnlock();
    void writeLock() throw();
    void writeUnlock();
    bool isReadLock();
    bool isWriteLock();
    bool isUnlock();
private:
    set<t_id> _nodes;

    /*
     * map<source_id, map<target_id, edge,id>
     */
    map<t_id,map<t_id,t_id> > _edges;
    map<t_id,set<t_id> > _reverse_edges;
    set<t_id> _bloom_edges;

    /*
     * 0 = unlocked
     * 1 = read locked
     * 2 = write locked
     */
    char _lock_flag;
    unsigned short int _rlock_count;

    friend ostream& operator<<(ostream& os, const Graph& o);
};

#endif	/* _GRAPH_H */
