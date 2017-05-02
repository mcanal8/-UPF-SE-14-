#include <iostream>
#include <fstream>
#include <string>

class Converter{

	private:

	public:
	
	//constructor
	Converter();

	//Destructor
	~Converter();

	//Methods
	virtual: 
	void convert(const char* original, std::string converted);

};
