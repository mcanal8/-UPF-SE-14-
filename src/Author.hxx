#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "Collection.hxx"



class Author{

	private:
		std::string _name, _catalogue, _stringnum;
		bool _contracted;
		std::vector<Work*> listOfWorks;
		int _comptador;	
		std::string status;
		std::vector<Client*> listOfClients;

	public:
	//Constructor
	Author();

	//Destructor
	~Author();

	//Methods
	std::string getName();//Added in First test P2
	void setName(std::string newname);//Added in Second test P2
	bool isContracted(); //Added in third test P2
	void contract(); //Added in fourth test P2
	
	std::string catalogue();//Added in P3: Test 1.
	void addWork(std::string workname, int worknum, std::string file);//Added in P3 Test 2
	Work& findWork(const std::string& workname);//Added in P3 Test 4
	void name(std::string inserted_name);//Added in P3 test 6
	std::string description();//Added in P3 test 6
	void subscribeClient(Client* clientSelected);
	void notify(const std::string workName, const std::string authorName);
	
};


