#include "MeltingPotOnline.hxx"
#include "authorException.hxx"
#include "fileException.hxx"
#include "topicException.hxx"
#include "clientException.hxx"






	//This function is the constructor of the class
	MeltingPotOnline::MeltingPotOnline(){
		_catalogue = "";
		_topicDescription = "";
		converter.add( "html" );
		converter.add( "pdf_print" );
		converter.add( "pdf_mark" );
		associatedTopic = false;
	}

	//This function is the destructor of the class
	MeltingPotOnline::~MeltingPotOnline(){
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]){
				delete listOfAuthors[i];
			}
		}


		for(i = 0; i < Topics.size(); i++){
			if(Topics[i]){
				delete Topics[i];
			}
		}

		for(i = 0; i < listOfClients.size(); i++){
			if(listOfClients[i]){
				delete listOfClients[i];
			}
		}
	}

	//This function returns a string that contains the information of all the authors and works
	std::string MeltingPotOnline::catalogue(){ //Added on the first functional test
		
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			_catalogue = _catalogue.append(listOfAuthors[i]->description());
		}
		if (associatedTopic == true)	_catalogue = _catalogue.append(_topicDescription);
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
		std::string converterfile;
		
		std::string fullname( "originals/" ); // The file is on this folder
		fullname += file;
		std::ifstream fichero( fullname.c_str() ); //We usea ifstream to check if the file exists
				
		i = findAuthor(authorName);
		listOfAuthors[i]->addWork(title, worknum, file);

		if(fichero == 0){ //If the file does not exist (fichero is 0) we throw the file exception.
			throw fileException();
		}
		//std::cout << fullname << endl;
		//std::cout << authorName << endl;
		converterfile = "generated/" + authorName + " - " + title;
		std::cout << converterfile << endl;
		printf("\n");
		converter.convert(fullname, converterfile);
		
		
		
	}

	
	int MeltingPotOnline::findAuthor(std::string authorName){

		int posicio, i;
		bool found = false; //Added to check if function has to generate an exception
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]->getName() == authorName){
				posicio = i;
				found = true;
			}
		}
		if(found == false){ //Exception generated because we haven't found any author
			throw authorException(); 
		}
		return posicio;



	}
	void MeltingPotOnline::addTopic(std::string name){
		std::string topicName;
		topicName = name + "\n";
		Topic *newTopic = new Topic();
		newTopic->setName(topicName);
		Topics.push_back(newTopic);
	}


	std::string MeltingPotOnline::listTopics(){
		std::string returnString;
		for(int i = 0; i < Topics.size(); i++){
			returnString = returnString + Topics[i]->getName();
		}
		return returnString;
	}


	void MeltingPotOnline::associateTopicWithWork(std::string topic, std::string author, std::string work){
		
		if(Topics.size() < 1){
			throw topicException();
		}
		else{
			std::string authorName;
			int i = findAuthor(author);
			authorName = listOfAuthors[i]->getName();
			
			Work linkedWork = listOfAuthors[i]->findWork(work);
			linkedWork.associateTopic(topic);

			
			_topicDescription = _topicDescription + linkedWork.topics(); //ESTO SERA EL REFACTOR
			associatedTopic = true;

			/*for(int i = 0; i < Topics.size(); i++){
				if(Topics[i]->getName() == topic){
					Topics[i]->notify(work, author);
				}
				
			}*/
			/*printf("*************************************\n");
			printf("%s",Topics[0]->getName().c_str());*/
			Topics[0]->notify(work, author);
		}

	}

	void MeltingPotOnline::addClient(std::string name, std::string email){ //Creamos un nuevo cliente y lo añadimos a la lista
		Client *newClient = new Client();
		newClient->setName(name);
		newClient->setEmail(email);
		listOfClients.push_back(newClient);
	}

	std::string MeltingPotOnline::listClients(){ // Devuelve la información de todos los clientes de la lista
		std::string description;
		for(int i = 0; i < listOfClients.size(); i++){
			description = description + listOfClients[i]->description();
		}
		
		return description;
	}
	void MeltingPotOnline::subscribeClientToTopic(std::string clientName, std::string topicName){
		bool encontrado = false;
		bool encontrado2 = false;
		std::string nomDelTopic = topicName + "\n";
		Topic* topicSelected;
		Client* clientSelected;
		int i = 0;
		//Els busquem en el nostre MeltingPotOnline
		for(i = 0; i < Topics.size(); i++){
			if(Topics[i]->getName() == nomDelTopic){
				topicSelected = Topics[i];
				encontrado = true;
			}
		}
		for(i = 0; i < listOfClients.size(); i++){
			if(listOfClients[i]->getName() == clientName){
				clientSelected = listOfClients[i];
				encontrado2 = true;
			}
		}
		//Excepcions per si no existeixen	//Ja disenyat en refactors anteriors als  tests sense client/topic, per aixo aquests donen green.
		if (encontrado == false){
			throw topicException();
		}
		if (encontrado2 == false){
			throw clientException();
		}
				
		//Enllacem client al topic
		topicSelected->subscribeClient(clientSelected);
	}
	std::string MeltingPotOnline::listSubscribedToTopic(std::string topicName){
		std::string nomDelTopic = topicName + "\n";
		bool encontrado = false;
		Topic* topicSelected;
		std::string textARetornar = "";
		int i = 0;
		//El busquem en el nostre MeltingPotOnline
		for(i = 0; i < Topics.size(); i++){
			if(Topics[i]->getName() == nomDelTopic){
				topicSelected = Topics[i];
				encontrado = true;
			}
		}
		//Excepcion per si no existeix topic
		if (encontrado == false){
			throw topicException();
		}
		//Extreiem nom del client lligat al topic seleccionat
		textARetornar = textARetornar + topicSelected->getClient(); //el metode ja retorna la llista de clients del topic
		return textARetornar;
	}
