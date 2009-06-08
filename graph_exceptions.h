/*! \file graph_exceptions.h
    \author sebastien heymann
    \date 4 juin 2009, 10:36
    \version 0.1
 */

#ifndef _GRAPH_EXCEPTIONS_H
#define	_GRAPH_EXCEPTIONS_H


#include <exception>
#include <string>
#include <sstream>
#include "typedefs.h"

namespace libgexf {

    /*! \class ReadLockException
        \brief Exception occuring on a read-lock.
     */
    class ReadLockException : public std::exception {
    public:
        ReadLockException(const std::string what) throw() { _text = what; };
        virtual ~ReadLockException() throw() {};
        virtual const char* what() const throw() {
            return (const char *)(_text.c_str());
        }
    private:
        std::string _text;
    };


    class WriteLockException : public std::exception {
    public:
        WriteLockException(const std::string what) throw() { _text = what; };
        virtual ~WriteLockException() throw() {};
        virtual const char* what() const throw() {
            return (const char *)(_text.c_str());
        }
    private:
        std::string _text;
    };
    

    /*! \class MessageExceptionBuilder
        \brief Facility to create messages about a given node_id
     */
    class MessageExceptionBuilder {
    public:
        static std::string buildString(std::string message, t_id node_id) {
            std::ostringstream ostr;
            ostr << ": " << node_id;
            return message + ostr.str();
        }
        virtual void abstractClass() = 0;
    };

}

#endif	/* _GRAPH_EXCEPTIONS_H */

