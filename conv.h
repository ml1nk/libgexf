/*! \file conv.h
    \author sebastien heymann
    \date 15 juillet 2009, 18:36
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

#ifndef _CONV_H
#define	_CONV_H

#include "typedefs.h"
#include <string>
#include <libxml/xmlstring.h>

namespace libgexf {

class Conv {
public:
    Conv();
    Conv(const Conv& orig);
    virtual ~Conv();

    static xmlChar* convertInput(const char *in, const char *encoding);
    static t_id xmlCharToId(const xmlChar* str);
    static t_id strToId(const std::string str);
    static std::string xmlCharToStr(const xmlChar* str);
    static unsigned int xmlCharToUnsignedInt(const xmlChar* str);
    static std::string idToStr(const t_id id);
    static std::string unsignedIntToStr(const unsigned int i);
    static unsigned int strToUnsignedInt(const std::string str);
    static std::string edgeTypeToStr(const t_edge_type t);
    static std::string attrTypeToStr(const t_attr_type t);
private:
    virtual void f() = 0;
};

} /* namespace libgexf */

#endif	/* _CONV_H */

