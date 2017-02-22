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
	void setName(std::string newname);//Added in Second test
	bool isContracted(); //Added in third test
	std::string contract(); //Added in fourth test
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
void Author::setName(std::string newname){
		
	_name = newname;
}

//Added in third test
bool Author::isContracted(){
	return _contracted;
}

//Added in fourth test
std::string Author::contract(){
	_contracted = true;
	return _name;
}

