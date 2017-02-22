#include <iostream>
#include <cstring>

class Author{

	private:
		std::string _name, _catalogue;
		bool _contracted;

	public:
	//Constructor
	Author();

	//Methods
	std::string getName();//Added in First test P2
	void setName(std::string newname);//Added in Second test P2
	bool isContracted(); //Added in third test P2
	void contract(); //Added in fourth test P2
	
	std::string catalogue();//Added in P3: Test 1.
	
};


