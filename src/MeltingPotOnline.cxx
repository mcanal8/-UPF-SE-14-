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
	string MeltingPotOnline::catalogue(){ //Added on the first functional test
		
		int i;
		for(i = 0; i < listOfAuthors.size(); i++){
			_catalogue = _catalogue.append(listOfAuthors[i]->description());
		}
		if (associatedTopic == true)	_catalogue = _catalogue.append(_topicDescription);
		return _catalogue;

	}

	//This function is used to add a new author to the system
	void MeltingPotOnline::addAuthor(const string authorName, bool isContracted){ //Added on the second functional test
		Author *newAuthor = new Author();
		newAuthor->name(authorName);
		if(isContracted){
			newAuthor->contract();
		}
	
		listOfAuthors.push_back( newAuthor );
		//_catalogue = _catalogue.append(newAuthor->description());
	}

	//This function is used to add a new work to a specific author.
	void MeltingPotOnline::addWork(const string authorName, const string title, int worknum, string file){ //Added on the fifth functional test 
		int i;
		string converterfile;
		
		string fullname( "originals/" ); // The file is on this folder
		fullname += file;
		ifstream fichero( fullname.c_str() ); //We usea ifstream to check if the file exists
				
		i = findAuthor(authorName);
		listOfAuthors[i]->addWork(title, worknum, file);

		if(fichero == 0){ //If the file does not exist (fichero is 0) we throw the file exception.
			throw fileException();
		}
		//cout << fullname << endl;
		//cout << authorName << endl;
		converterfile = "generated/" + authorName + " - " + title;
		cout << converterfile << endl;
		printf("\n");
		converter.convert(fullname, converterfile);
		
		
		
	}

	
	int MeltingPotOnline::findAuthor(string authorName){

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
	void MeltingPotOnline::addTopic(string name){
		string topicName;
		topicName = name + "\n";
		Topic *newTopic = new Topic();
		newTopic->setName(topicName);
		Topics.push_back(newTopic);
	}


	string MeltingPotOnline::listTopics(){
		string returnString;
		for(int i = 0; i < Topics.size(); i++){
			returnString = returnString + Topics[i]->getName();
		}
		return returnString;
	}


	void MeltingPotOnline::associateTopicWithWork(string topic, string author, string work){
		
		if(Topics.size() < 1){
			throw topicException();
		}
		else{

			string topicName;
			string authorName;
			int i = findAuthor(author);
			authorName = listOfAuthors[i]->getName();
			
			Work linkedWork = listOfAuthors[i]->findWork(work);
			linkedWork.associateTopic(topic);

			
			_topicDescription = _topicDescription + linkedWork.topics(); //ESTO SERA EL REFACTOR
			associatedTopic = true;

			for(int i = 0; i < Topics.size(); i++){
				topicName = Topics[i]->getName();
				topicName.erase (topicName.length() - 1,2);
				if(topicName == topic){
					Topics[i]->notify(work, author);
				}	
			}
		}

	}

	void MeltingPotOnline::addClient(string name, string email){ //Creamos un nuevo cliente y lo añadimos a la lista
		Client *newClient = new Client();
		newClient->setName(name);
		newClient->setEmail(email);
		listOfClients.push_back(newClient);
	}

	string MeltingPotOnline::listClients(){ // Devuelve la información de todos los clientes de la lista
		string description;
		for(int i = 0; i < listOfClients.size(); i++){
			description = description + listOfClients[i]->description();
		}
		
		return description;
	}
	void MeltingPotOnline::subscribeClientToTopic(string clientName, string topicName){
		bool encontrado = false;
		bool encontrado2 = false;
		string nomDelTopic = topicName + "\n";
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
	string MeltingPotOnline::listSubscribedToTopic(string topicName){
		string nomDelTopic = topicName + "\n";
		bool encontrado = false;
		Topic* topicSelected;
		string textARetornar = "";
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
