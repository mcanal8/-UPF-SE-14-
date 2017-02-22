#include <string>
#include <iostream>

class Work{
	//Atributos
	private:
	std::string a, original;
	int isbn_num;
	
	public:
	virtual std::string aText(std::string texto = "-1, '-- Untitled --', ''"){
		return texto;
	}

	//constructor
	Work();

	//Methods
	std::string title();//Added in First test
	void title(std::string stringTitle);//Added in Second test
	int isbn();//Added in Third test
	void isbn(int nou_ISBN);//Added in Fourth test
	std::string originalFile();//Added in test Five
	void originalFile(std::string new_original);//Added in the Last test
};

Work::Work(){
		a = "-- Untitled --";
		isbn_num = -1;	
		original = "";	
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
