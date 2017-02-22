#include <string>
#include <iostream>
#include <sstream>

class Work{
	//Atributos
	private:
	std::string a, original, texto;
	int isbn_num;
	
	public:
	
	//constructor
	Work();

	//Methods
	std::string title();//Added in First test
	void title(std::string stringTitle);//Added in Second test
	int isbn();//Added in Third test
	void isbn(int nou_ISBN);//Added in Fourth test
	std::string originalFile();//Added in test Five
	void originalFile(std::string new_original);//Added in test Six
	std::string aText();//Added in test Seven
};

Work::Work(){
		a = "-- Untitled --";
		isbn_num = (-1);	
		original = "";
		texto = "";	
	}
	
	std::string Work::title(){
		return a;
	}
	void Work::title(std::string stringTitle){
		a = stringTitle;	
 	}
	int Work::isbn(){
		return isbn_num;
	}
	void Work::isbn(int nou_ISBN){
		isbn_num = nou_ISBN;	
 	}
	std::string Work::originalFile(){
		return original;
	}
	void Work::originalFile(std::string new_original){
		original = new_original;
	}
	std::string Work::aText(){
		//convert int isbn to string isbn		
		std::string s;
		std::stringstream out;
		out << isbn();
		//s is isbn string converted
		s = out.str();
		//texto sera el siguiente
		texto = s+", '"+a+"',"+" '"+original+"'"; 
		return texto;
	}
