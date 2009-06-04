/*! \file graph_exceptions.h
    \author sebastien
    \date 4 juin 2009, 10:36
    \version 0.1
 */

#ifndef _GRAPH_EXCEPTIONS_H
#define	_GRAPH_EXCEPTIONS_H


#include <exception>
#include <string>

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

}

#endif	/* _GRAPH_EXCEPTIONS_H */

