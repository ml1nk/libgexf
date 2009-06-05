/*! \file gexf.h
    \author sebastien heymann
    \date 17 avril 2009, 17:28
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

#ifndef _GEXF_H
#define	_GEXF_H

#include <iostream>
#include "graph.h"

namespace libgexf {

    /*! \class GEXF
        \brief GEXF class

        GEXF class containing :
        \li graph topology
        \li data attributes (currently not available)
        \li hierarchy (currently not available)
        \li viz data (currently not available)
        \li dynamics (currently not available)
     */
    class GEXF {
    public:
        GEXF();
        //GEXF(const GEXF& orig);
        virtual ~GEXF();

        Graph& getGraph();

        /*! \var Graph _graph
            \brief Topology structure
         */
        Graph _graph;
    private:
        friend std::ostream& operator<<(std::ostream& os, const GEXF& o);
    };

}

#endif	/* _GEXF_H */

