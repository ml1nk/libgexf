/**
 * File:   inserters.cpp
 * Author: sebastien heymann
 *
 * Created on 22 avril 2009, 15:57
 *
 * Generic inserters for object dumping
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

#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef unsigned int t_id;

//-----------------------------------------
ostream& operator<<(ostream& os, const set<t_id>& o) {
//-----------------------------------------
set<t_id>::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << " " << *it;
    }

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, const map<t_id,t_id>& o) {
//-----------------------------------------
map<t_id,t_id>::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << endl;
    }

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, const multimap<t_id,t_id>& o) {
//-----------------------------------------
multimap<t_id,t_id>::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << endl;
    }

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, const map<t_id,set<t_id> >& o) {
//-----------------------------------------
map<t_id,set<t_id> >::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << endl;
    }

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, const map<t_id,map<t_id,t_id> >& o) {
//-----------------------------------------
map<t_id,map<t_id,t_id> >::const_iterator it;

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << it->first << " => " << it->second << endl;
    }

    return os;
}
