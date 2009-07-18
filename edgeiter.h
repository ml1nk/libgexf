/*! \file edgeiter.h
    \author sebastien heymann
    \date 9 juillet 2009, 17:38
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

#ifndef _EDGEITER_H
#define	_EDGEITER_H

#include "typedefs.h"
#include "graph.h"

#include <map>

namespace libgexf {

class Graph;

class EdgeIter {
public:
    EdgeIter(const libgexf::Graph* g);
    virtual ~EdgeIter();

    EdgeIter* begin();
    bool hasNext() const;
    libgexf::t_id next();  /*!< Return an edge_id */

    libgexf::t_id currentSource() const;
    libgexf::t_id currentTarget() const;
    float currentProperty(libgexf::t_edge_property prop) const;  /*!< Return the value or 0 by default */
private:
    const Graph* _graph;
    std::map<t_id,std::map<t_id,t_id> >::const_iterator _it;
    std::map<t_id,t_id>::const_iterator _it2;
    unsigned int _cpt;
    unsigned int _nb_items;
    t_id _current_edge_id;
    t_id _current_source;
    t_id _current_target;
    // TODO: optimizing for removing _current_source and _current_target copy
};

}

#endif	/* _EDGEITER_H */

