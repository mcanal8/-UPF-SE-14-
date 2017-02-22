#include "Author.hxx"

Author::Author(){
	_name = "--A_Name--";
	_contracted = false;
	_catalogue = "";
}

//Added in First test
std::string Author::getName(){
	
	return _name;
	
}

//Added in Second test
void Author::setName(std::string newname){
		
	_name = newname;
}

//Added in third test
bool Author::isContracted(){
	return _contracted;
}

//Added in fourth test
void Author::contract(){
	_contracted = true;
}
std::string Author::catalogue(){//Retorna el cataleg de l'Autor corresponent.
		return _catalogue;
	}
