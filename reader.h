/*! \file reader.h
    \author sebastien heymann
    \date 19 juin 2009, 12:37
    \version 0.1
 */

#ifndef _READER_H
#define	_READER_H

#include "gexf.h"

/*#include <libxml++/libxml++.h>
#include <libxml++/parsers/textreader.h>*/


namespace libgexf {

/*! \class Reader
    \brief Topology structure of the graph
 */
class Reader {
public:
    Reader();
    Reader(const Reader& orig);
    virtual ~Reader();

    void init(std::string filename);
    //int relaxNGValidate(std::string schema);
    //void slurp();
private:
    //xmlpp::TextReader reader;
    GEXF* _gexf;
};

}

#endif	/* _READER_H */

