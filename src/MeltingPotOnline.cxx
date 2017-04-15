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

	//This function returns a string that contains the information of all the authors and works
	std::string MeltingPotOnline::catalogue(){ //Added on the first functional test
		
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			_catalogue = _catalogue.append(listOfAuthors[i]->description());
		}
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
		//_catalogue = _catalogue.append(newAuthor->description());
	}

	//This function is used to add a new work to a specific author.
	void MeltingPotOnline::addWork(const std::string authorName, const std::string title, int worknum, std::string file){ //Added on the fifth functional test 
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]->getName() == authorName){
			
				listOfAuthors[i]->addWork(title, worknum, file);
			}
		}
	}

