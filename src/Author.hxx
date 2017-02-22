#include <iostream>
#include <cstring>

class Author{

	private:
		std::string catalogue = "";

	public:
	//Constructor
	Author();

	//Methods
	std::string catalogue();//Added in first Test
};

Author::Author(){

}

//Added in first Test
std::string Author::catalogue(){
	return catalogue;
}