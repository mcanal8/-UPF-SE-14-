#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include "Work.hxx"


class Collection{
	private:
	std::string a, _worksofCollection;
	bool ispublished, isTrue;
	std::vector<Work*> listOfWorks;
	int _comptador;

	public:
	
	//constructor
	Collection();

	//Destructor
	~Collection();

	//Methods
	std::string title();//Added in First test METHOD
	std::string title(std::string stringTitle);//Added in Second test METHOD
	bool isPublished();//Added in Third test
	void publish();//Added in fourth test
	void withdraw();//Added in the last test	
	std::string workList();
	void addWork(Work &newWork);
};


 	
	
