/* 
 * File:   NodeIter.h
 * Author: sebastien
 *
 * Created on 9 juillet 2009, 15:48
 */

#ifndef _NodeIter_H
#define	_NodeIter_H

#include "typedefs.h"
#include "graph.h"

#include <set>

namespace libgexf {

class Graph;

class NodeIter {
public:
    NodeIter(const Graph* g);
    virtual ~NodeIter();

    NodeIter* begin();
    bool hasNext() const;
    t_id next();
    //t_id currentItem();
    //bool eq(NodeIter it);
private:
    const Graph* _graph;
    std::set<t_id>::const_iterator _it;
    unsigned int _cpt;
    unsigned int _nb_items;
};

} /* namespace libgexf */

#endif	/* _NodeIter_H */

