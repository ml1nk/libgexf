/* 
 * File:   abstractparser.h
 * Author: sebastien
 *
 * Created on 17 juillet 2009, 15:02
 */

#ifndef _ABSTRACTPARSER_H
#define	_ABSTRACTPARSER_H

#include "gexf.h"
#include <libxml/xmlreader.h>

namespace libgexf {

class AbstractParser {
public:
    virtual void bind(GEXF* gexf) = 0;
    virtual void processNode(xmlTextReaderPtr reader, const xmlChar* name) = 0;
private:

};

}

#endif	/* _ABSTRACTPARSER_H */

