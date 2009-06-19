/*! \file reader.cpp
    \author sebastien heymann
    \date 19 juin 2009, 12:37
    \version 0.1
 */

#include "reader.h"

#include <libxml++/libxml++.h>
#include <libxml++/parsers/textreader.h>
#include <iostream>
using namespace std;

namespace libgexf {

Reader::Reader(): _gexf(0) {
}

Reader::Reader(const Reader& orig) {
}

Reader::~Reader() {
}

//-----------------------------------------
void Reader::init(string filename) {
//-----------------------------------------
    try {
        xmlpp::TextReader reader(filename);
        while(reader.read()) {
            // doing some stuff....reader.get_name()
            std::cout << "name: " << reader.get_name() << std::endl;
            if(reader.has_attributes()) {
                reader.move_to_first_attribute();
                do {
                    // doing some stuff....reader.get_name() reader.get_value()
                    std::cout << "name: " << reader.get_name() << std::endl;
                    std::cout << "value: " << reader.get_value() << std::endl;
                } while(reader.move_to_next_attribute());
                reader.move_to_element();
            }
            if(reader.has_value()) {
                // doing some stuff....reader.get_value()
                std::cout << "value: " << reader.get_value() << std::endl;
            }
        }
    } catch(const std::exception& e) {
        std::cout << "Exception occured while reading the file " << filename << ": " << e.what() << std::endl;
        throw(e);
    }
}

}


/*
name: gexf
name: xmlns
value: http://www.gephi.org/gexf/1.1draft
name: xmlns:viz
value: http://www.gephi.org/gexf/1.1draft/viz
name: xmlns:xsi
value: http://www.w3.org/2001/XMLSchema-instance
name: xsi:schemaLocation
value: http://www.gephi.org/gexf/1.1draft                       http://gephi.org/gexf/1.1draft.xsd
name: version
value: 1.1
name: #text
value:

name: meta
name: lastmodifieddate
value: 2009-03-20
name: #text
value:

name: creator
name: #text
value: Gephi.org
name: creator
name: #text
value:

name: description
name: #text
value: A hello world! file
name: description
name: #text
value:

name: meta
name: lastmodifieddate
value: 2009-03-20
name: #text
value:

name: graph
name: mode
value: static
name: defaultedgetype
value: directed
name: #text
value:

name: nodes
name: #text
value:

name: node
name: id
value: 0
name: label
value: Hello
name: #text
value:

name: node
name: id
value: 1
name: label
value: Word
name: #text
value:

name: nodes
name: #text
value:

name: edges
name: #text
value:

name: edge
name: id
value: 0
name: source
value: 0
name: target
value: 1
name: #text
value:

name: edges
name: #text
value:

name: graph
name: mode
value: static
name: defaultedgetype
value: directed
name: #text
value:

name: gexf
name: xmlns
value: http://www.gephi.org/gexf/1.1draft
name: xmlns:viz
value: http://www.gephi.org/gexf/1.1draft/viz
name: xmlns:xsi
value: http://www.w3.org/2001/XMLSchema-instance
name: xsi:schemaLocation
value: http://www.gephi.org/gexf/1.1draft                       http://gephi.org/gexf/1.1draft.xsd
name: version
value: 1.1

*/