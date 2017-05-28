#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class channelException: public exception
{
  virtual const char* what() const throw()
  {
    return "The thematic channel does not exist"; 	//Missatge de l'excepció
  }
};
