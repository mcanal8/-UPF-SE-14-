#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "The work does not exist"; 	//Missatge de l'excepció
  }
} myex;
