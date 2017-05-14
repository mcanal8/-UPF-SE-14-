#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Topic.hxx"


using namespace std;

class Work{
	//Atributos
	private:
		string a, original, texto, textoTopic;
		int isbn_num;
		vector<Topic*> TopicsOfaWork;
	public:
	
	//constructor
	Work();

	//destructor
	~Work();

	//Methods
	string title();//Added in First test
	void title(string stringTitle);//Added in Second test
	int isbn();//Added in Third test
	void isbn(int nou_ISBN);//Added in Fourth test
	string originalFile();//Added in test Five
	void originalFile(string new_original);//Added in test Six
	string aText();//Added in test Seven
	void associateTopic(string newTopic);
	string topics();
};

