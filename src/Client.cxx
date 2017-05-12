#include "Client.hxx"

//constructor
Client::Client(){
		name = "";
		email = "";
		
		
	}
	//destructor
	Client::~Client(){
		
	}
	void Client::setName(string clientName){
		name = clientName;	
	}
	
	void Client::setEmail(string clientEmail){
		email = " <"+clientEmail+">\n";
	}
	
	string Client::description(){
		_description.append(name + email);
		return _description;

	}
	
	
