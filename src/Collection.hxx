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
	void publish();//Added in fourth test
	void withdraw();//Added in the last test
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
	//Added in fourth test
	void Collection::publish(){
		ispublished = true;
	} 
	//Added in the last test
	void Collection::withdraw(){
		ispublished = false;
	}
 	
	
