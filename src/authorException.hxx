#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class authorException: public exception
{
  virtual const char* what() const throw()
  {
    return "The author does not exist"; 	//Missatge de l'excepció
  }
};
