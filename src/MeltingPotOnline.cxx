#include "MeltingPotOnline.hxx"



	//This function is the constructor of the class
	MeltingPotOnline::MeltingPotOnline(){
		_catalogue = "";
	}

	//This function is the destructor of the class
	MeltingPotOnline::~MeltingPotOnline(){
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]){
				delete listOfAuthors[i];
			}
		}
	}

	//This function returns a string that contains the information of all the authors
	std::string MeltingPotOnline::catalogue(){ //Added on the first functional test
	
		return _catalogue;

	}

	//This function is used to add a new author to the system
	void MeltingPotOnline::addAuthor(const std::string authorName, bool isContracted){ //Added on the second functional test
		Author *newAuthor = new Author();
		newAuthor->name(authorName);
		if(isContracted){
			newAuthor->contract();
		}
	
		listOfAuthors.push_back( newAuthor );
		_catalogue = _catalogue.append(newAuthor->description());
	}

