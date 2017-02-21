#include <string>
#include <iostream>

class Work{
	//Atributos
	private:
	std::string a;
	int isbn_num;
	
	public:
	
	//constructor
	Work();

	//Methods
	std::string title();
	std::string title(std::string stringTitle);
	int isbn();
	void isbn(int nou_ISBN);
};

Work::Work(){
		a = "-- Untitled --";
		isbn_num = -1;		
	}
	
	std::string Work::title(){
		return a;
	}
	std::string Work::title(std::string stringTitle){
		a = stringTitle;	
 		return a;
 	}
	int Work::isbn(){
		return isbn_num;
	}
	void Work::isbn(int nou_ISBN){
		isbn_num = nou_ISBN;	
 	}
