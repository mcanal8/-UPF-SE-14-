#include "Client.hxx"

//constructor
Client::Client(){
		name = "";
		email = "";
		_description = "";
		
	}
	//destructor
	Client::~Client(){
		
	}
	void Client::setName(string clientName){
		//name = clientName;	
	}
	
	void Client::setEmail(string clientEmail){
		//email = "<"+clientEmail+">";
	}
	
	string Client::description(){
		_description.append(name + email);
		return _description;

	}
	
	
