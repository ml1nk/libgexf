/*! \file data.h
    \author sebastien heymann
    \date 30 juin 2009, 13:35
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

#ifndef _DATA_H
#define	_DATA_H

#include "typedefs.h"
#include "attributeiter.h"
#include <string>
#include <map>

namespace libgexf {

class AttributeIter;

class Data {
public:
    Data();
    Data(const Data& orig);
    virtual ~Data();

    std::string getLabel(const t_id node_id) const;
    bool hasLabel(const t_id node_id) const;
    void setLabel(const t_id node_id, const std::string label);

    void addNodeAttributeColumn(const t_id id, const std::string title, const t_attr_type type);
    void addEdgeAttributeColumn(const t_id id, const std::string title, const t_attr_type type);

    void setNodeAttributeDefault(const t_id attr_id, const std::string default_value);
    void setEdgeAttributeDefault(const t_id attr_id, const std::string default_value);

    void setNodeValue(const t_id node_id, const t_id attr_id, const std::string value);
    void setEdgeValue(const t_id node_id, const t_id attr_id, const std::string value);

    AttributeIter* getNodeAttributeColumn() const;
    AttributeIter* getEdgeAttributeColumn() const;

    std::string getNodeAttribute(const t_id node_id, const t_id attr_id) const;
    std::string getEdgeAttribute(const t_id edge_id, const t_id attr_id) const;

    std::map<t_id,std::string > getNodeAttributeRow(const t_id node_id) const;
    std::map<t_id,std::string > getEdgeAttributeRow(const t_id edge_id) const;

    std::string getNodeAttributeDefault(const t_id attr_id) const;
    std::string getEdgeAttributeDefault(const t_id attr_id) const;

    bool hasNodeAttributeDefault(const t_id attr_id) const;
    bool hasEdgeAttributeDefault(const t_id attr_id) const;

    void clearNodeAttributes(const t_id node_id);
    void clearEdgeAttributes(const t_id edge_id);
    void clear();
    void clearEdgesAttributes();
private:
    std::map<t_id,std::string > _node_labels; /*!< map<node_id, label > */

    std::map<t_id,std::string > _node_attributes; /*!< map<attr_id, title > */
    std::map<t_id,t_attr_type > _node_attributes_types; /*!< map<attr_id, type > */
    std::map<t_id,std::string > _node_default_values; /*!< map<attr_id, default > */
    std::map<t_id,std::map<t_id,std::string > > _node_values; /*!< map<node_id, map<attr_id, type > > */

    std::map<t_id,std::string > _edge_attributes; /*!< map<attr_id, title > */
    std::map<t_id,t_attr_type > _edge_attributes_types; /*!< map<attr_id, type > */
    std::map<t_id,std::string > _edge_default_values; /*!< map<attr_id, default > */
    std::map<t_id,std::map<t_id,std::string > > _edge_values; /*!< map<edge_id, map<attr_id, type > > */
private:
    void init();
    friend std::ostream& operator<<(std::ostream& os, const Data& o);
    unsigned int countNodeAttributeColumn() const;
    unsigned int countEdgeAttributeColumn() const;
    friend class AttributeIter;
};

} /* namespace libgexf */

#endif	/* _DATA_H */

