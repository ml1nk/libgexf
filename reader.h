/*! \file reader.h
    \author sebastien heymann
    \date 19 juin 2009, 12:37
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

#ifndef _READER_H
#define	_READER_H

#include "gexf.h"
#include "gexfparser.h"
#include <libxml/xmlreader.h>


namespace libgexf {

/*! \class Reader
    \brief Topology structure of the graph
 */
class Reader {
public:
    Reader();
    Reader(const std::string filepath);
    Reader(const Reader& orig);
    virtual ~Reader();

    GEXF getGEXFCopy();

    void init(const std::string filepath);
    //int relaxNGValidate(const std::string schema);
    void slurp();
private:
    void createParser();
    void streamFile();
private:
    GEXF* _gexf;
    GexfParser _parser;
    std::string _filepath;
};

} /* namespace libgexf */

#endif	/* _READER_H */
