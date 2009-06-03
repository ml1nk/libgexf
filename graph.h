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

    void add_node(const t_id id);
    void add_edge(const t_id id, const t_id source_id, const t_id target_id);
    void remove_node(const t_id id);
    void remove_edge(const t_id source_id, const t_id target_id);
    void remove_in_edges(const t_id target_id);
    void remove_out_edges(const t_id source_id);

    bool contains_node(const t_id id) const;
    bool contains_edge(const t_id source_id, const t_id target_id) const;

    unsigned int get_node_count() const;
    unsigned int get_edge_count() const;
    unsigned int get_degree(const t_id node_id) const;
    set<t_id> get_neighbors(const t_id node_id) const;

    void clear_edges(const t_id node_id);
    void clear();
    void clear_edges();
private:
    set<t_id> _nodes;

    /*
     * map<source_id, map<target_id, edge,id>
     */
    map<t_id,map<t_id,t_id> > _edges;
    map<t_id,set<t_id> > _reverse_edges;
    set<t_id> _bloom_edges;

    friend ostream& operator<<(ostream& os, const Graph& o);
};

#endif	/* _GRAPH_H */

