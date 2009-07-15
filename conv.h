/* 
 * File:   conv.h
 * Author: sebastien
 *
 * Created on 15 juillet 2009, 18:36
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
    static std::string xmlCharToStr(const xmlChar* str);
    static unsigned int xmlCharToUnsignedInt(const xmlChar* str);
    static std::string unsignedIntToStr(const unsigned int i);
    static unsigned int strToUnsignedInt(const std::string str);
    static std::string edgeTypeToStr(const t_edge_type t);
    static std::string attrTypeToStr(const t_attr_type t);
private:
    virtual void f() = 0;
};

} /* namespace libgexf */

#endif	/* _CONV_H */

