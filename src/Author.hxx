#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

class Author{

	private:
		std::string _name, _catalogue, _stringnum;
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
	void addWork(std::string workname, int worknum, std::string file);//Added in P3 Test 2
	
};


