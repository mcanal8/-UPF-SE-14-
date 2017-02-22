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
	void contract(); //Added in fourth test
	
	std::string catalogue();
	
};


