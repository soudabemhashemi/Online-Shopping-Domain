#include "exception.hpp"

const char* Find_path::what() const throw(){
      return "Not Found\n"; 
 }

const char* Permission::what() const throw(){
      return "Permission Denied\n"; 
 }

const char* Bad_request::what() const throw(){
      return "Bad Request\n"; 
 }
