#include "Topic.hxx"






	//This function is the constructor of the class
	Topic::Topic(){
		
	}

	//This function is the destructor of the class, afegit vector de clients.
	Topic::~Topic(){
		for(int i = 0; i < listOfClients.size(); i++){
			if(listOfClients[i]){
				delete listOfClients[i];
			}
		}
	}

	void Topic::setName(string newName){
		name = newName;
	}

	string Topic::getName(){
		return name;
	}
	string Topic::getClient(){
		string returnString;
		for(int i = 0; i < listOfClients.size(); i++){
			returnString = returnString + listOfClients[i]->getName() + "\n";
		}
		return returnString;
		
	}
	void Topic::subscribeClient(Client* clientSelected){
		listOfClients.push_back(clientSelected);	//Canviat de variable client unica a llista de clients en un sol topic
	}
