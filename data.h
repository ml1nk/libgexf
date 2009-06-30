/*! \file data.h
    \author sebastien heymann
    \date 30 juin 2009, 13:35
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

#ifndef _DATA_H
#define	_DATA_H

#include "typedefs.h"
#include <string>

namespace libgexf {

class Data {
public:
    Data();
    Data(const Data& orig);
    virtual ~Data();

    std::string getLabel(const t_id node_id) const;
    bool hasLabel(const t_id node_id) const;
    void setLabel(const t_id node_id, const std::string label);

private:
    std::map<t_id,std::string > _node_labels; /*!< map<node_id, label > */
   // std::map<t_id,std::map<t_node_data,void*> > _node_data; /*!< map<node_id, map<k, v> > */
private:
    friend std::ostream& operator<<(std::ostream& os, const Data& o);
};

} /* namespace libgexf */

#endif	/* _DATA_H */

