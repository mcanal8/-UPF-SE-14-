#include "Collection.hxx"

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
