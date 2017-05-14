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
	string Client::getName(){
		return name;
	}
	void Client::update(const string workName, const string authorName){
		string to;
		string subject;
		email.erase (email.length() - 1,2); //Para eliminar un salto de linea de sobras
		to = "A client" + email;
		subject = "new work " + workName + " by " + authorName;
		MailStub::theInstance().sendMail(to, subject);
	}
	
	
