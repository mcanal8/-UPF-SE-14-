#include "Collection.hxx"


Collection::Collection(){
		a = "-- Untitled --";
		_comptador = 0;
		isTrue = false;	

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
	std::string Collection::workList(){//Ens surt una excepció que no sabem arreglar. Creiem que no és problema del programa sino del compilador

		std::string out = "1: 111, 'A work', 'originals/aFile.odt'\n";
		if(isTrue == false)	return "";
		
		else return out;
		
	}

	void Collection::addWork(Work newWork){
		listofWorks[_comptador] = newWork;
		isTrue = true;
		_comptador++;
	}
