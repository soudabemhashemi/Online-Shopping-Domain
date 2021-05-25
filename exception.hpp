#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <exception>
using namespace std;

class Find_path : public exception {
   virtual const char* what() const throw();
};

class Permission : public exception {
   virtual const char* what() const throw();
};

class Bad_request : public exception {
   virtual const char* what() const throw();
};

#endif
