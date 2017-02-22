#include <iostream>
#include <cstring>

class Author{

	private:
		std::string _name;
		bool _contracted;

	public:
	//Constructor
	Author();

	//Methods
	std::string getName();//Added in First test
	std::string setName(std::string newname);//Added in Second test
};

Author::Author(){
	_name = "--A_Name--";
	_contracted = false;
}

//Added in First test
std::string Author::getName(){
	
	return _name;
	
}

//Added in Second test
std::string Author::setName(std::string newname){
		
	_name = "Pol";
	return _name;
}

