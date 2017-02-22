#include <iostream>
#include <cstring>

class Author{

	private:
		std::string a;

	public:
	//Constructor
	Author();

	//Methods
	std::string catalogue();
};

Author::Author(){

}

std::string Author::catalogue(){
	return a;
}