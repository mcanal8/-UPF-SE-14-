#include "Collection.hxx"


Collection::Collection(){
		a = "-- Untitled --";
		_comptador = 0;
		isTrue = false;	
		ispublished = false;
	}


	Collection::~Collection(){
		int i;
		for(i = 0; i < listOfWorks.size(); i++){
			if(listOfWorks[i]){
				delete listOfWorks[i];
			}
		}
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
	std::string Collection::workList(){
		
		return _worksofCollection;
		
	}

	void Collection::addWork(Work &newWork){
	
		listOfWorks.push_back( &newWork );
		_comptador++;
		_worksofCollection = _worksofCollection.append("1: " + newWork.aText()+"\n");//Amb la funció append afegim al final de l'string _catalogue el nou text
	}
