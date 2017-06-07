#ifndef Topic_hxx
#define Topic_hxx

#include <string>
#include <vector>
#include "Client.hxx"
#include "MailStub.hxx"
#include "Channel.hxx"


using namespace std;

class Topic
{

	private:
		string _name;
		vector<Client*> listOfClients;
		vector<Channel*> listOfChannels;
	public:
	
	//constructor
	Topic();

	//Destructor
	~Topic();

	//Methods
	void setName(const string & newName);
	string getName();
	string getClient() const;
	void subscribeClient(Client* clientSelected);
	void subscribeChannel(Channel* channelSelected);
	void notify(const string & workName, const string & authorName);
};

#endif
