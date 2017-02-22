#include <string>
#include <iostream>
#include <sstream>

class Work{
	//Atributos
	private:
	std::string a, original, texto;
	int isbn_num;
	
	public:
	
	//constructor
	Work();

	//Methods
	std::string title();//Added in First test
	void title(std::string stringTitle);//Added in Second test
	int isbn();//Added in Third test
	void isbn(int nou_ISBN);//Added in Fourth test
	std::string originalFile();//Added in test Five
	void originalFile(std::string new_original);//Added in test Six
	std::string aText();//Added in test Seven
};

