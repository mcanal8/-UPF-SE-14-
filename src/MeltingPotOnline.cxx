#include "MeltingPotOnline.hxx"
#include "authorException.hxx"
#include "fileException.hxx"






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
		
		
		std::string fullname( "originals/" ); // The file is on this folder
		fullname += file;
		std::ifstream fichero( fullname.c_str() ); //We usea ifstream to check if the file exists
				
		i = findAuthor(authorName);
		listOfAuthors[i]->addWork(title, worknum, file);

		if(fichero == 0){ //If the file does not exist (fichero is 0) we throw the file exception.
			throw fileException();
		}	
		
		
	}
	int MeltingPotOnline::findAuthor(std::string authorName){

		int posicio, i;
		bool found = false; //Added to check if function has to generate an exception
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]->getName() == authorName){
				posicio = i;
				//listOfAuthors[i]->addWork(title, worknum, file);
				found = true;
			}
		}
		if(found == false){ //Exception generated because we haven't found any author
			throw authorException(); 
		}
		return posicio;



	}

