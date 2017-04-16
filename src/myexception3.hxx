#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class myexception3: public exception
{
  virtual const char* what() const throw()
  {
    return "The original file does not exist"; 	//Missatge de l'excepció
  }
} myex3;
