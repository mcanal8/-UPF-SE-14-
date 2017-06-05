#include "Client.hxx"

//constructor
Client::Client(){
		name = "";
		email = "";
		smsnum = "";
		whatsappnum = "";
		
		
	}
	//destructor
	Client::~Client(){
		
	}
	void Client::setName(const string &clientName){
		name = clientName;	
	}
	void Client::setSmsnum(const string &numerosms){
		smsnum = numerosms;	
	}
	void Client::setWhatsappnum(const string &numerowhatsapp){
		whatsappnum = numerowhatsapp;	
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
		if((smsnum == "") && (whatsappnum == "")){		
			string to;
			string subject;
			email.erase (email.length() - 1,2); //Para eliminar un salto de linea de sobras
			to = name + email;
			subject = "new work " + workName + " by " + authorName;
			MailStub::theInstance().sendMail(to, subject);
		}
		else{
			string text;
			text = "[MeltingPot] new work "+ workName + " by " + authorName;

			if(smsnum != ""){
				SmsStub::theInstance().sendSms(smsnum, text);		
			}

			if(whatsappnum != ""){
				WhatsappStub::theInstance().sendWhatsapp(whatsappnum, text);
			}
		}
		
	}
	
	
