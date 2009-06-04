/* 
 * File:   graph_exceptions.h
 * Author: sebastien
 *
 * Created on 4 juin 2009, 10:36
 */

#ifndef _GRAPH_EXCEPTIONS_H
#define	_GRAPH_EXCEPTIONS_H


#include <exception>
#include <string>
using namespace std;

class ReadLockException : public exception {
public:
    ReadLockException(const string what) throw() { _text = what; };
    virtual ~ReadLockException() throw() {};

    virtual const char* what() const throw() {
        return (const char *)(_text.c_str());
    }
private:
    string _text;
};


class WriteLockException : public exception {
public:
    WriteLockException(const string what) throw() { _text = what; };
    virtual ~WriteLockException() throw() {};
    virtual const char* what() const throw() {
        return (const char *)(_text.c_str());
    }
private:
    string _text;
};


#endif	/* _GRAPH_EXCEPTIONS_H */

