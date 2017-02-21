#include <iostream>
#include <cstring>

class Collection{
	private:
	std::string a;
	bool ispublished = false;
	public:
	
	//constructor
	Collection();

	//Methods
	std::string title();//Added in First test METHOD
	std::string title(std::string stringTitle);//Added in Second test METHOD
	bool isPublished();//Added in Third test
	
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
 	bool Collection::isPublished(){
		return ispublished;
	}
 	
	
