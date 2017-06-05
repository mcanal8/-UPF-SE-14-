#ifndef Topic_hxx
#define Topic_hxx

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.hxx"
#include "MailStub.hxx"
#include "Channel.hxx"


using namespace std;

class Topic
{

	private:
		string name;
		vector<Client*> listOfClients;
		vector<Channel*> listOfChannels;
	public:
	
	//constructor
	Topic();

	//Destructor
	~Topic();

	//Methods
	void setName(string newName);
	string getName();
	string getClient();
	void subscribeClient(Client* clientSelected);
	void subscribeChannel(Channel* channelSelected);
	void notify(const string workName, const string authorName);
};

#endif
