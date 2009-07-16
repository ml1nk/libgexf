/*! \file inserters.cpp
    \author sebastien heymann
    \date 22 avril 2009, 15:57
    \version 0.1
    \brief Generic inserters for object dumping
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

#include "typedefs.h"
#include <iostream>
#include <set>
#include <map>
#include <string>

namespace libgexf {

//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const std::set<t_id>& o) {
//-----------------------------------------
std::set<t_id>::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << " " << *it;
    }

    return os;
}

//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const std::map<t_id,t_id>& o) {
//-----------------------------------------
std::map<t_id,t_id>::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << std::endl;
    }

    return os;
}

//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const std::multimap<t_id,t_id>& o) {
//-----------------------------------------
std::multimap<t_id,t_id>::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << std::endl;
    }

    return os;
}

//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const std::map<t_id,std::set<t_id> >& o) {
//-----------------------------------------
std::map<t_id,std::set<t_id> >::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << std::endl;
    }

    return os;
}

//-----------------------------------------
std::ostream& operator<<(std::ostream& os, const std::map<t_id,std::map<t_id,t_id> >& o) {
//-----------------------------------------
std::map<t_id,std::map<t_id,t_id> >::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << std::endl;
    }

    return os;
}

}
