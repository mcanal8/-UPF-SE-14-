#include <string>
#include <iostream>

class Work{
	//Atributos
	private:
	std::string a;
	int isbn_num;
	
	public:
	virtual void isbn(int isbn_num_nou){

 		

 	}


	//constructor
	Work();

	//Methods
	std::string title();
	std::string title(std::string stringTitle);
	int isbn();
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
