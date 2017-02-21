#include <iostream>
#include <cstring>

class Collection{
	private:
	std::string a;
	
	public:
	//constructor
	Collection();

	//Methods
	std::string title();//Added in First test METHOD
	std::string title(std::string stringTitle);//Added in Second test METHOD
	std::string isPublished();//Added in Third test
	
};

Collection::Collection(){
		a = "-- Untitled --";		
	}
	//Added in First test METHOD
	std::string Collection::title(){
		return a;
	}
	//Added in Second test METHOD
	std::string Collection::title(std::string stringTitle){
		a = stringTitle;	
 		return a;
 	}
 	//Added in third test
 	std::string Collection::isPublished(){
		return 0;
	}
 	
	
