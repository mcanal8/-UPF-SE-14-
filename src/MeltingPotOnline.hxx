#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Author.hxx"
#include "ConverterGroup.hxx"
#include "Channel.hxx"


using namespace std;

class MeltingPotOnline{

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
	string catalogue();	//Added on the first functional test
	void addAuthor(const string authorName, bool isContracted); //Added on the second functional test       
	void addWork(const string authorName, const string title, int worknum, string file); //Added on the 5th functional test
	int findAuthor(string authorName);
	void generateConversions();
	void addTopic(std::string name); // Added on P6 
	string listTopics(); //Added on P6
	void associateTopicWithWork(string topic, string author, string work);
	void addClient(string name, string email);
	string listClients();
	void subscribeClientToTopic(string clientName, string topicName);
	string listSubscribedToTopic(string topicName);
	void subscribeClientToAuthor(string clientName, string authorName);
	void addChannel(const string name, const string description);
	string listThematicChannels();
};


 	
	
