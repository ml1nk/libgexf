/* 
 * File:   attvalueiter.h
 * Author: sebastien
 *
 * Created on 17 juillet 2009, 22:35
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

#ifndef _ATTVALUEITER_H
#define	_ATTVALUEITER_H

#include "typedefs.h"
#include "data.h"

#include <map>
#include <string>

namespace libgexf {

class Data;

class AttValueIter {
public:
    enum Type { NODE, EDGE };
public:
    AttValueIter(const Data* d, const libgexf::t_id id, const AttValueIter::Type t);
    virtual ~AttValueIter();

    AttValueIter* begin();
    bool hasNext() const;
    libgexf::t_id next();

    std::string currentValue() const;
    std::string currentName() const;
private:
    const Data* _data;
    Type _t;
    t_id _id;
    std::map<t_id,std::map<t_id,std::string > >::const_iterator _it_row;
    std::map<t_id,std::string >::const_iterator _it;
    unsigned int _cpt;
    unsigned int _nb_items;
};

}

#endif	/* _ATTVALUEITER_H */

