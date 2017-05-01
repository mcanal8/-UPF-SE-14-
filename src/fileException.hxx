#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class fileException: public exception
{
  virtual const char* what() const throw()
  {
    return "The original file does not exist"; 	//Missatge de l'excepció
  }
};
