/* 
 * File:   inserters.h
 * Author: sebastien
 *
 * Created on 19 juin 2009, 16:19
 */

#ifndef _INSERTERS_H
#define	_INSERTERS_H

#include "typedefs.h"

namespace libgexf {

extern std::ostream& operator<<(std::ostream& os, const std::set<t_id>& o);

extern std::ostream& operator<<(std::ostream& os, const std::map<t_id,t_id>& o);

extern std::ostream& operator<<(std::ostream& os, const std::multimap<t_id,t_id>& o);

extern std::ostream& operator<<(std::ostream& os, const std::map<t_id,std::set<t_id> >& o);

extern std::ostream& operator<<(std::ostream& os, const std::map<t_id,std::map<t_id,t_id> >& o);

}

#endif	/* _INSERTERS_H */

