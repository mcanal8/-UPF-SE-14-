#include <iostream>
#include <cstring>
#include "Work.hxx"


class Collection{
	private:
	std::string a;
	bool ispublished = false, isTrue;
	Work listofWorks[100];
	int _comptador;
	public:
	
	//constructor
	Collection();

	//Methods
	std::string title();//Added in First test METHOD
	std::string title(std::string stringTitle);//Added in Second test METHOD
	bool isPublished();//Added in Third test
	void publish();//Added in fourth test
	void withdraw();//Added in the last test	
	std::string workList();
	void addWork(Work newWork);
};


 	
	
