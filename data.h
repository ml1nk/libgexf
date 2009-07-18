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
#include "attvalueiter.h"
#include <string>
#include <map>

namespace libgexf {

class AttributeIter;
class AttValueIter;

class Data {
public:
    Data();
    Data(const Data& orig);
    virtual ~Data();

    std::string getLabel(const libgexf::t_id node_id) const;
    bool hasLabel(const libgexf::t_id node_id) const;
    void setLabel(const libgexf::t_id node_id, const std::string label);

    void addNodeAttributeColumn(const libgexf::t_id id, const std::string title, const libgexf::t_attr_type type);
    void addEdgeAttributeColumn(const libgexf::t_id id, const std::string title, const libgexf::t_attr_type type);

    void setNodeAttributeDefault(const libgexf::t_id attr_id, const std::string default_value);
    void setEdgeAttributeDefault(const libgexf::t_id attr_id, const std::string default_value);

    void setNodeValue(const libgexf::t_id node_id, const libgexf::t_id attr_id, const std::string value);
    void setEdgeValue(const libgexf::t_id node_id, const libgexf::t_id attr_id, const std::string value);

    libgexf::AttributeIter* getNodeAttributeColumn() const;
    libgexf::AttributeIter* getEdgeAttributeColumn() const;

    std::string getNodeAttribute(const libgexf::t_id node_id, const libgexf::t_id attr_id) const;
    std::string getEdgeAttribute(const libgexf::t_id edge_id, const libgexf::t_id attr_id) const;

    libgexf::AttValueIter* getNodeAttributeRow(const libgexf::t_id node_id) const;
    libgexf::AttValueIter* getEdgeAttributeRow(const libgexf::t_id edge_id) const;

    std::string getNodeAttributeDefault(const libgexf::t_id attr_id) const;
    std::string getEdgeAttributeDefault(const libgexf::t_id attr_id) const;

    bool hasNodeAttributeDefault(const libgexf::t_id attr_id) const;
    bool hasEdgeAttributeDefault(const libgexf::t_id attr_id) const;

    void clearNodeAttributes(const libgexf::t_id node_id);
    void clearEdgeAttributes(const libgexf::t_id edge_id);
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
    friend class AttValueIter;
};

} /* namespace libgexf */

#endif	/* _DATA_H */

