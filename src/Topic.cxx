#include "Topic.hxx"


	//This function is the constructor of the class
	Topic::Topic(){
		_name = "";
	}

	//This function is the destructor of the class, afegit vector de clients.
	Topic::~Topic(){
		unsigned int i;
		for(i = 0; i < listOfClients.size(); i++){
			if(listOfClients[i]){
				//delete listOfClients[i];
			}
		}
		for(i = 0; i < listOfChannels.size(); i++){
			if(listOfChannels[i]){
				delete listOfChannels[i];
			}
		}
	}

	void Topic::setName(const string & newName){
		_name = newName;
	}

	string Topic::getName(){
		return _name;
	}
	string Topic::getClient() const{
		string returnString;
		for(unsigned int i = 0; i < listOfClients.size(); i++){
			returnString = returnString + listOfClients[i]->getName() + "\n";
		}
		return returnString;
		
	}

	void Topic::subscribeClient(Client* clientSelected){
		listOfClients.push_back(clientSelected);	//Canviat de variable client unica a llista de clients en un sol topic
	}

	void Topic::subscribeChannel(Channel* channelSelected){

		listOfChannels.push_back(channelSelected);
	}

	void Topic::notify(const string & workName, const string & authorName){
		for(unsigned int i = 0; i < listOfClients.size(); i++){ //Recorremos todo el vector de clientes suscritos y les notificamos
			listOfClients[i]->update(workName, authorName);
		}
		for(unsigned int i = 0; i < listOfChannels.size(); i++){
			listOfChannels[i]->update(workName, authorName);
		}
	}
