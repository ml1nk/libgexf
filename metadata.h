/*! \file metadata.h
    \author sebastien heymann
    \date 30 juin 2009, 14:14
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

#ifndef _METADATA_H
#define	_METADATA_H

#include <string>

namespace libgexf {

class MetaData {
public:
    MetaData();
    MetaData(const MetaData& orig);
    virtual ~MetaData();

    std::string getVersion() const;
    std::string getXmlns() const;
    std::string getXsi() const;
    std::string getSchema() const;
    std::string getVariant() const;
    std::string getCreator() const;
    std::string getDescription() const;
    std::string getKeywords() const;
    std::string getLastModifiedDate() const;

    void setVersion(const std::string version);
    void setXmlns(const std::string xmlns);
    void setXsi(const std::string xsi);
    void setSchema(const std::string schema);
    void setVariant(const std::string variant);
    void setCreator(const std::string creator);
    void setDescription(const std::string description);
    void setKeywords(const std::string keywords);
    void setLastModifiedDate(const std::string lastmodifieddate);
private:
    void init();
private:
    std::string _version;
    std::string _xmlns;
    std::string _xsi;
    std::string _schema;
    std::string _variant;
    std::string _creator;
    std::string _description;
    std::string _keywords;
    std::string _lastmodifieddate;
private:
    friend std::ostream& operator<<(std::ostream& os, const MetaData& o);
};

}

#endif	/* _METADATA_H */

