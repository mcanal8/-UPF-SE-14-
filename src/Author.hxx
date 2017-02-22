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
};

Author::Author(){
	_name = "--A_Name--";
	_contracted = false;
}

//Added in First test
std::string Author::getName(){
	
	return "";
	
}

