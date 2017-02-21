#include <string>
#include <iostream>

class Work{
	//Atributos
	private:
	std::string a, original;
	int isbn_num;
	
	public:
	
	//constructor
	Work();

	//Methods
	std::string title();
	void title(std::string stringTitle);
	int isbn();
	void isbn(int nou_ISBN);
	std::string originalFile();
	void originalFile(std::string new_original);
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
