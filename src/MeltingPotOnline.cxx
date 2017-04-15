#include "MeltingPotOnline.hxx"




	MeltingPotOnline::MeltingPotOnline(){
		_catalogue = "";
	}


	MeltingPotOnline::~MeltingPotOnline(){

	}

	std::string MeltingPotOnline::catalogue(){ //Added on the first functional test
	
		return _catalogue;

	}

	void MeltingPotOnline::addAuthor(const std::string authorName, bool isContracted){
		Author *newAuthor = new Author();
		newAuthor->name(authorName);
		if(isContracted){
			newAuthor->contract();
		}
		//newAuthor->_contracted(isContracted);
	
		listOfAuthors.push_back( newAuthor );
		_catalogue = _catalogue.append(newAuthor->description());
	}

