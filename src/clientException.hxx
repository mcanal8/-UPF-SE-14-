#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class clientException: public exception
{
  virtual const char* what() const throw()
  {
    return "The client does not exist"; 	//Missatge de l'excepció
  }
};
