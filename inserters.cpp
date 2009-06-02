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

//-----------------------------------------
ostream& operator<<(ostream& os, const set<unsigned long int>& o) {
//-----------------------------------------
set<unsigned long int>::const_iterator it;
    
    os << "  " << "set<unsigned long int> [" << endl << "        ";

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << " " << *it;
    }

    os << endl << "      ]" << endl;

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, const map<unsigned long int,unsigned long int>& o) {
//-----------------------------------------
map<unsigned long int,unsigned long int>::const_iterator it;

    os << "  " << "map<unsigned long int,unsigned long int> [" << endl << "        ";

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << (*it).first << " => " << (*it).second << endl << "      ";
    }

    os << endl << "      ]" << endl;

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, const multimap<unsigned long int,unsigned long int>& o) {
//-----------------------------------------
multimap<unsigned long int,unsigned long int>::const_iterator it;

    os << "  " << "multimap<unsigned long int,unsigned long int> [" << endl << "        ";

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << (*it).first << " => " << (*it).second << endl << "          ";
    }

    os << endl << "        ]" << endl;

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, map<unsigned long int,set<unsigned long int> > o) {
//-----------------------------------------
map<unsigned long int,set<unsigned long int> >::iterator it;

    os << "  " << "map<unsigned long int,set<unsigned long int> > [" << endl << "        ";

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << (*it).first << " => " << (*it).second << endl << "\t\t\t";
    }

    os << endl << "      ]" << endl;

    return os;
}

//-----------------------------------------
ostream& operator<<(ostream& os, map<unsigned long int,map<unsigned long int,unsigned long int> > o) {
//-----------------------------------------
map<unsigned long int,map<unsigned long int,unsigned long int> >::iterator it;

    os << "  " << "map<unsigned long int,map<unsigned long int,unsigned long int> > [" << endl << "        ";

    for ( it=o.begin() ; it != o.end(); it++ ) {
        os << (*it).first << " => " << (*it).second << endl << "\t\t\t";
        //os << (*it).first << endl << "      ";
    }

    os << endl << "      ]" << endl;

    return os;
}
