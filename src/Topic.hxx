#include <iostream>
#include <fstream>
#include <string>
#include "Client.hxx"


using namespace std;

class Topic
{

	private:
		string name;
		Client client;
	public:
	
	//constructor
	Topic();

	//Destructor
	~Topic();

	//Methods
	void setName(string newName);
	string getName();
	Client getClient();
	void addClient(Client* clientSelected);
};
