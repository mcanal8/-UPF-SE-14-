#include "MeltingPotOnline.hxx"




	MeltingPotOnline::MeltingPotOnline(){
		_catalogue = "";
	}


	MeltingPotOnline::~MeltingPotOnline(){
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]){
				delete listOfAuthors[i];
			}
		}
	}

	std::string MeltingPotOnline::catalogue(){ //Added on the first functional test
	
		return _catalogue;

	}

	void MeltingPotOnline::addAuthor(const std::string authorName, bool isContracted){ //Added on the second functional test
		Author *newAuthor = new Author();
		newAuthor->name(authorName);
		if(isContracted){
			newAuthor->contract();
		}
	
		listOfAuthors.push_back( newAuthor );
		_catalogue = _catalogue.append(newAuthor->description());
	}

