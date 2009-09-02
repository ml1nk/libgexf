/* 
 * File:   MemoryValidator.h
 * Author: sebastien
 *
 * Created on 2 septembre 2009, 14:53
 */

#ifndef _MEMORYVALIDATOR_H
#define	_MEMORYVALIDATOR_H

#include "gexf.h"

namespace libgexf {

    class GEXF;

    /*! \class MemoryValidator
        \brief Static class to check data correctness
     */
    class MemoryValidator {
    public:
        MemoryValidator();
        MemoryValidator(const MemoryValidator& orig);
        virtual ~MemoryValidator();

        /*!
         *  \brief Check the data correctness
         *
         *  \li verify if each node has a label
         *  \li verify if each attvalue has a value or a defaultvalue
         */
        static bool run(const GEXF& gexf);
    private:
        static bool checkNodeLabels(const GEXF& gexf);
        static bool checkAttValues(const GEXF& gexf);
        static bool checkAttValueType(const GEXF& gexf, const std::string& value, const libgexf::t_attr_type type, const t_id elem_id, const t_id attr_id="", const bool isNode=true);

        virtual void f() = 0;
    };

} /* namespace libgexf */

#endif	/* _MEMORYVALIDATOR_H */

