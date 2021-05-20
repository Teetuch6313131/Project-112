#include <iostream> 
#include <exception> 
class my_cin: public exception
{
    virtual const char* what() const throw(){
      return "Sorry Not Number!!";
    }
    
}cinf;