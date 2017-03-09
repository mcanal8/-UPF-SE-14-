#include "Author.hxx"


Author::Author(){
	_name = "--A_Name--";
	_contracted = false;
	_catalogue = "";
	_stringnum = "";
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

//Added in P3 Test 2
void Author::addWork(std::string workname, int worknum, std::string file){
	//COM QUE EL NOSTRE COMPILADOR NO DETECTA EL TOSTRING(), HEM DE FER SERVIR AIXO PER PASAR A STRING	
	//convert int worknum to string worknum	
	std::string s;	
	std::stringstream out;
	out << worknum;
	//s is string worknum (converted)
	s = out.str();
	
	_catalogue = _catalogue.append("\t"+ s + ", '" + workname + "', 'originals/" + file +"'\n");//Amb la funció append afegim al final de l'string _catalogue el nou text
	
}

