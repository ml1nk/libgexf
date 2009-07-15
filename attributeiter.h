/* 
 * File:   attributeiter.h
 * Author: sebastien
 *
 * Created on 15 juillet 2009, 14:27
 */

#ifndef _ATTRIBUTEITER_H
#define	_ATTRIBUTEITER_H

#include "typedefs.h"
#include "data.h"

#include <map>
#include <string>

namespace libgexf {

class Data;

class AttributeIter {
public:
    enum Type { NODE, EDGE };

public:
    AttributeIter(const Data* d, AttributeIter::Type t);
    virtual ~AttributeIter();

    AttributeIter* begin();
    bool hasNext() const;
    t_id next();

    std::string currentTitle() const;
    t_attr_type currentType() const;
private:
    const Data* _data;
    Type _t;
    std::map<t_id,std::string >::const_iterator _it;
    unsigned int _cpt;
    unsigned int _nb_items;
};

} /* namespace libgexf */

#endif	/* _ATTRIBUTEITER_H */

