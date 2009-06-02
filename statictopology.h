/* 
 * File:   statictopology.h
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

#ifndef _STATICTOPOLOGY_H
#define	_STATICTOPOLOGY_H

#include <set>
#include <map>
#include <iostream>
using namespace std;

class StaticTopology {
public:
    StaticTopology();
    StaticTopology(const StaticTopology& orig);
    virtual ~StaticTopology();

    void add_node(const unsigned long int id);
    void remove_node(const unsigned long int id);
    void add_edge(const unsigned long int id, const unsigned long int source_id, const unsigned long int target_id);
    void remove_edge(const unsigned long int source_id, const unsigned long int target_id);
    void remove_in_edges(const unsigned long int target_id);
    void remove_out_edges(const unsigned long int source_id);

    unsigned long int num_nodes();
    unsigned long int num_edges();
private:
    set<unsigned long int> _nodes;

    /*
     * map<source_id, map<target_id, edge,id>
     */
    map<unsigned long int,map<unsigned long int,unsigned long int> > _edges_source_target;
    
    map<unsigned long int,set<unsigned long int> > _edges_target_source;

    friend ostream& operator<<(ostream& os, const StaticTopology& o);
};

#endif	/* _STATICTOPOLOGY_H */

