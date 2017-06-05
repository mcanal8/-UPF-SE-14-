#include <string>
#include <iostream>
#include <sstream>
#include "MailStub.hxx"



using namespace std;

class Client{
	//Atributos
	private:
		string name, email, _description, smsnum, whatsappnum;
		
	public:
	
	//constructor
	Client();

	//destructor
	~Client();

	//Methods
	void setName(const string &clientName);
	void setSmsnum(const string &numerosms);
	void setWhatsappnum(const string &numerowhatsapp);
	void setEmail(string clientEmail);
	string description();
	string getName();
	void update(const string workName, const string authorName);
};
