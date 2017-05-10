#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Author.hxx"
#include "ConverterGroup.hxx"


class MeltingPotOnline{

	private:

		std::vector<Author*> listOfAuthors;
		std::string _catalogue;
		ConverterGroup converter;
		std::vector<std::string> Topics;

	public:
	
	//constructor
	MeltingPotOnline();

	//Destructor
	~MeltingPotOnline();

	//Methods
	std::string catalogue();	//Added on the first functional test
	void addAuthor(const std::string authorName, bool isContracted); //Added on the second functional test       
	void addWork(const std::string authorName, const std::string title, int worknum, std::string file); //Added on the 5th functional test
	int findAuthor(std::string authorName);
	void generateConversions();
	void addTopic(std::string name); // Added on P6 
	std::string listTopics(); //Added on P6
	void associateTopicWithWork(std::string topic, std::string author, std::string work);

};


 	
	
