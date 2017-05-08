#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class formatException: public exception
{
  virtual const char* what() const throw()
  {
    return "Unsupported format"; 	//Missatge de l'excepció
  }
};
