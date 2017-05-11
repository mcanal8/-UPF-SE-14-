#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Topic
{

	private:
		string name;

	public:
	
	//constructor
	Topic();

	//Destructor
	~Topic();

	//Methods
	void setName(string newName);
	string getName();
};
