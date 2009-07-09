/* 
 * File:   edgeiter.h
 * Author: sebastien
 *
 * Created on 9 juillet 2009, 17:38
 */

#ifndef _EDGEITER_H
#define	_EDGEITER_H

#include "typedefs.h"
#include "graph.h"

#include <map>

namespace libgexf {

class Graph;

class EdgeIter {
public:
    EdgeIter(const Graph* g);
    virtual ~EdgeIter();

    EdgeIter* begin();
    bool hasNext() const;
    t_id next();  /*!< Return an edge_id */

    t_id currentSource() const;
    t_id currentTarget() const;
private:
    const Graph* _graph;
    std::map<t_id,std::map<t_id,t_id> >::const_iterator _it;
    std::map<t_id,t_id>::const_iterator _it2;
    unsigned int _cpt;
    unsigned int _nb_items;
    t_id _current_source;
    t_id _current_target;
};

}

#endif	/* _EDGEITER_H */

