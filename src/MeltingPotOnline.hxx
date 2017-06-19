//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <fstream>
#include "Author.hxx"
#include "ConverterGroup.hxx"
#include "Channel.hxx"
#include "gui/Model.hxx"


using namespace std;

class MeltingPotOnline : public Model{

	private:

		vector<Author*> listOfAuthors;
		string _catalogue, _topicDescription;
		ConverterGroup converter;
		vector<Topic*> Topics;
		bool associatedTopic;
		vector<Client*> listOfClients;
		vector<Channel*> Channels;

	public:
	
	//constructor
	MeltingPotOnline();

	//Destructor
	~MeltingPotOnline();

	//Methods
	string catalogue() const;	//Added on the first functional test
	void addAuthor(const string & name, bool contracted); //Added on the second functional test       
	void addWork(const string & authorName, const string & title, int isbn, const string & original); //Added on the 5th functional test
	int findAuthor(string authorName);
	void generateConversions();
	void addTopic(string & name); // Added on P6 
	string listTopics() const; //Added on P6
	void associateTopicWithWork(const string & topicName, const string & authorName, const string & workTitle);
	void addClient(string name, string email);
	string listClients();
	void subscribeClientToTopic(string clientName, string topicName);
	string listSubscribedToTopic(string topicName);
	void subscribeClientToAuthor(string clientName, string authorName);
	void addChannel(const string name, const string description);
	string listThematicChannels();
	string rssByChannel(const string title);
	void subscribeChannelToAuthor(const string channelName, const string authorName);
	void subscribeChannelToTopic(const string channelName, const string topicName);
	void clientPrefersSms(const string nombreCliente, const string numeroDeCliente);
	void clientPrefersWhatsapp(const string nombreCliente, const string numeroDeCliente);
};


 	
	
