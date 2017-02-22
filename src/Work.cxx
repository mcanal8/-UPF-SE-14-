#include "Work.hxx"

Work::Work(){
		a = "-- Untitled --";
		isbn_num = (-1);	
		original = "";
		texto = "";	
	}
	
	std::string Work::title(){
		return a;	// Retorna el titol del work seleccionat
	}
	void Work::title(std::string stringTitle){
		a = stringTitle;	// Modifica el titol del work seleccionat
 	}
	int Work::isbn(){
		return isbn_num;	// Retorna ISBN del work seleccionat
	}
	void Work::isbn(int nou_ISBN){
		isbn_num = nou_ISBN;	// Modifica el ISBN del work seleccionat
 	}
	std::string Work::originalFile(){
		return original;	//Retorna l'originalFile d'un work seleccionat
	}
	void Work::originalFile(std::string new_original){
		original = new_original;	// Modifica l'originalFile del work seleccionat
	}
	std::string Work::aText(){ //Mostra toda la informacio d'un work determinat
		//convert int isbn to string isbn		
		std::string s;
		std::stringstream out;
		out << isbn();
		//s is isbn string converted
		s = out.str();
		//texto sera el siguiente (añadimos condicional para diferenciar cuando sea por defecto)
		if (isbn() == -1){
			texto = s+", '"+a+"',"+" '"+original+"'";
		}
		else 	texto = s+", '"+a+"',"+" 'originals/"+original+"'"; 
		return texto;
	}
