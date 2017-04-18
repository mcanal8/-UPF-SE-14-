#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class workException: public exception
{
  virtual const char* what() const throw()
  {
    return "The work does not exist"; 	//Missatge de l'excepció
  }
} myex;
