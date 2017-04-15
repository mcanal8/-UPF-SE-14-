#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include "Author.hxx"


class MeltingPotOnline{

	private:

		std::vector<Author*> listOfAuthors;
		std::string _catalogue;

	public:
	
	//constructor
	MeltingPotOnline();

	//Destructor
	~MeltingPotOnline();

	//Methods
	std::string catalogue();	//Added on the first functional test
	void addAuthor(const std::string authorName, bool isContracted);         

};


 	
	
