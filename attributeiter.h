/*! \file attributeiter.h
    \author: sebastien heymann
    \date 15 juillet 2009, 14:27
    \version
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

#ifndef _ATTRIBUTEITER_H
#define	_ATTRIBUTEITER_H

#include "typedefs.h"
#include "data.h"

#include <map>
#include <string>

namespace libgexf {

class Data;

class AttributeIter {
public:
    enum Type { NODE, EDGE };

public:
    AttributeIter(const Data* d, const AttributeIter::Type t);
    virtual ~AttributeIter();

    AttributeIter* begin();
    bool hasNext() const;
    libgexf::t_id next();

    std::string currentTitle() const;
    libgexf::t_attr_type currentType() const;
private:
    const Data* _data;
    Type _t;
    std::map<t_id,std::string >::const_iterator _it;
    unsigned int _cpt;
    unsigned int _nb_items;
};

} /* namespace libgexf */

#endif	/* _ATTRIBUTEITER_H */

