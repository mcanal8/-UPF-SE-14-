#include <iostream>
#include <cstring>

class Collection{
	private:
	std::string a;
	bool ispublished = false;
	public:
	
	//constructor
	Collection();

	//Methods
	std::string title();//Added in First test METHOD
	std::string title(std::string stringTitle);//Added in Second test METHOD
	bool isPublished();//Added in Third test
	void publish();//Added in fourth test
	void withdraw();//Added in the last test
};

Collection::Collection(){
		a = "-- Untitled --";		
	}
	//Retorna titol d'una coleccio seleccionada
	std::string Collection::title(){
		return a;
	}
	//Modifica titol d'una coleccio seleccionada
	std::string Collection::title(std::string stringTitle){
		a = stringTitle;	
 		return a;
 	}
 	//Indicador de si una coleccio ha sigut o no publicada
 	bool Collection::isPublished(){
		return ispublished;
	}
	//Modifiquen la condicio de publicat o no d'una coleccio seleccionada
	void Collection::publish(){
		ispublished = true;
	} 
		//Added in the last test
	void Collection::withdraw(){
		ispublished = false;
	}
 	
	
