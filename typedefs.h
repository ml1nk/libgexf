/*! \file typedefs.h
    \author sebastien
    \date 8 juin 2009, 14:22
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

#ifndef _TYPEDEFS_H
#define	_TYPEDEFS_H

#include <string>

namespace libgexf {

typedef unsigned int t_id; /*!< Type of all IDs */

enum t_graph { GRAPH_DIRECTED, GRAPH_UNDIRECTED, GRAPH_MIXED }; /*!<Available graph types */

enum t_edge_property { EDGE_TYPE, EDGE_COUNT, EDGE_WEIGHT }; /*!<Available edge properties */

enum t_edge_type { EDGE_DIRECTED, EDGE_UNDIRECTED, EDGE_DOUBLE }; /*!<Available edge types */


typedef float t_edge_value;

}

#endif	/* _TYPEDEFS_H */

