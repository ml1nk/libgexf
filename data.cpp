/*! \file data.cpp
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

#include <map>

#include "data.h"
#include <sstream>

using namespace std;

namespace libgexf {

Data::Data(): _node_labels() {
}

Data::Data(const Data& orig): _node_labels(orig._node_labels) {
}

Data::~Data() {
}

//-----------------------------------------
string Data::getLabel(const t_id node_id) const {
//-----------------------------------------
string label = "";
    map<t_id,string >::const_iterator it = _node_labels.find(node_id);
    if(it != _node_labels.end()) {
        label = it->second;
    }

    return label;
}

//-----------------------------------------
bool Data::hasLabel(const t_id node_id) const {
//-----------------------------------------
    return _node_labels.find(node_id) != _node_labels.end();
}

//-----------------------------------------
void Data::setLabel(const t_id node_id, const std::string label) {
//-----------------------------------------
    _node_labels[node_id] = label;
}


//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const Data& o) {
//-----------------------------------------
    os << "Data [" << std::endl;

    std::map<t_id,std::string>::const_iterator it;

    for ( it=o._node_labels.begin() ; it != o._node_labels.end(); it++ ) {
        os << it->first << " => " << it->second << std::endl;
    }
    os << "]" << std::endl;
    return os;
}

} /* namespace libgexf */
