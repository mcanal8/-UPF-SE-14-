#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class topicException: public exception
{
  virtual const char* what() const throw()
  {
    return "The topic does not exist"; 	//Missatge de l'excepció
  }
};
