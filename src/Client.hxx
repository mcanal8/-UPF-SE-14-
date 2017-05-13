#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Client{
	//Atributos
	private:
		string name, email, _description;
		
	public:
	
	//constructor
	Client();

	//destructor
	~Client();

	//Methods
	void setName(string clientName);
	void setEmail(string clientEmail);
	string description();
	string getName();
};
