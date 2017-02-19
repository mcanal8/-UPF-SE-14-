#include <iostream>
#include <cstring>

class Collection{
	private:
	std::string a;
	
	public:
	//constructor
	Collection();

	//Methods
	std::string title();
	std::string title(std::string stringTitle);
	
};

Collection::Collection(){
		a = "-- Untitled --";		
	}
	std::string Collection::title(){
		return a;
	}
	std::string Collection::title(std::string stringTitle){
		a = stringTitle;	
 		return a;
 	}
	
