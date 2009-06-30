/* 
 * File:   inserters.h
 * Author: sebastien
 *
 * Created on 19 juin 2009, 16:19
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

#ifndef _INSERTERS_H
#define	_INSERTERS_H

#include "typedefs.h"

namespace libgexf {

extern std::ostream& operator<<(std::ostream& os, const std::set<t_id>& o);

extern std::ostream& operator<<(std::ostream& os, const std::map<t_id,t_id>& o);

extern std::ostream& operator<<(std::ostream& os, const std::multimap<t_id,t_id>& o);

extern std::ostream& operator<<(std::ostream& os, const std::map<t_id,std::set<t_id> >& o);

extern std::ostream& operator<<(std::ostream& os, const std::map<t_id,std::map<t_id,t_id> >& o);

}

#endif	/* _INSERTERS_H */

