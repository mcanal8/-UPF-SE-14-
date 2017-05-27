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
		unsigned int i;
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

		for(i = 0; i < Channels.size(); i++){
			if(Channels[i]){
				delete Channels[i];
			}
		}
	}

	//This function returns a string that contains the information of all the authors and works
	string MeltingPotOnline::catalogue(){ //Added on the first functional test
		
		unsigned int i;
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

	}

	//This function is used to add a new work to a specific author.
	void MeltingPotOnline::addWork(const string authorName, const string title, int worknum, string file){ //Added on the fifth functional test 
		unsigned int i;
		string converterfile;
		Author* authorSelected;
		
		string fullname( "originals/" ); // The file is on this folder
		fullname += file;
		ifstream fichero( fullname.c_str() ); //We usea ifstream to check if the file exists
				
		i = findAuthor(authorName);
		listOfAuthors[i]->addWork(title, worknum, file);

		if(fichero == 0){ //If the file does not exist (fichero is 0) we throw the file exception.
			throw fileException();
		}
		converterfile = "generated/" + authorName + " - " + title;
		converter.convert(fullname, converterfile);

		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]->getName() == authorName){
				authorSelected= listOfAuthors[i];
				//autorencontrado = true;
			}
		}
		authorSelected->notify(title, authorName);
		
	}

	
	int MeltingPotOnline::findAuthor(string authorName){

		int posicio; 
		unsigned int i;
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
		for(unsigned int i = 0; i < Topics.size(); i++){
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

			for(unsigned int i = 0; i < Topics.size(); i++){
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
		for(unsigned int i = 0; i < listOfClients.size(); i++){
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
		unsigned int i = 0;
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

		delete topicSelected;
		delete clientSelected;
	}
	string MeltingPotOnline::listSubscribedToTopic(string topicName){
		string nomDelTopic = topicName + "\n";
		bool encontrado = false;
		Topic* topicSelected;
		string textARetornar = "";
		unsigned int i = 0;
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

	void MeltingPotOnline::subscribeClientToAuthor(string clientName, string authorName){
		Author* authorSelected;
		Client* clientSelected;
		bool autorencontrado = false;
		bool clientencontrado = false;
		unsigned int i = 0;

		//Buscamos el autor seleccionado entre la lista de autores
		for(i = 0; i < listOfAuthors.size(); i++){
			if(listOfAuthors[i]->getName() == authorName){
				authorSelected= listOfAuthors[i];
				autorencontrado = true;
			}
		}
		//Buscamos el cliente seleccionado entre la lista de clientes
		for(i = 0; i < listOfClients.size(); i++){
			if(listOfClients[i]->getName() == clientName){
				clientSelected = listOfClients[i];
				clientencontrado = true;
			}
		}
		//Si no encontramos cliente o autor lanzamos exception
		if (autorencontrado == false){
			throw authorException();
		}
		if (clientencontrado == false){
			throw clientException();
		}
		//Suscribimos el cliente al autor
		authorSelected->subscribeClient(clientSelected);


	}

	void MeltingPotOnline::addChannel(const string name, const string description){
		//Creamos un nuevo channel y lo ponemos a la lista de channels
		Channel *newChannel = new Channel();
		newChannel->addChannel(name, description);
		Channels.push_back(newChannel);
	}

	string MeltingPotOnline::listThematicChannels(){
		//Retornamos una string con toda la información de todos los channels creados
		string textARetornar = "";
		unsigned int i = 0;

		//Exception por si no existe ningun channel
		/*if(Channels.size() < 1){
			throw channelException();
		}*/
		//El busquem en el nostre MeltingPotOnline
		//else{
			for(i = 0; i < Channels.size(); i++){
				textARetornar = textARetornar + Channels[i]->getChannel();
			}
		//}
		return textARetornar;
	}
