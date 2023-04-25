#ifndef Exceptions_h
#define Exceptions_h

#include <iostream>
#include <exception>

class BadIndex : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Index!";
    }
};

class BadLength : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Length!";
    }
};

#endif /* Exceptions_h */

