#include <string>
#include <iostream>

class Work{
	private:
	std::string a;
	
	
	public:
	virtual int isbn(int isbn_num = -1){
		return isbn_num;
	}
	//constructor
	Work();

	//Methods
	std::string title();
	std::string title(std::string stringTitle);
};

Work::Work(){
		a = "-- Untitled --";		
	}
	
	std::string Work::title(){
		return a;
	}
	std::string Work::title(std::string stringTitle){
		a = stringTitle;	
 		return a;
 	}
