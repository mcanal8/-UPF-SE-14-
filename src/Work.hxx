#include <string>
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
	void title(const string & stringTitle);//Added in Second test
	int isbn() const;//Added in Third test
	void isbn(const int nou_ISBN);//Added in Fourth test
	string originalFile();//Added in test Five
	void originalFile(const string & new_original);//Added in test Six
	string aText();//Added in test Seven
	void associateTopic(string newTopic);
	string topics();
};

