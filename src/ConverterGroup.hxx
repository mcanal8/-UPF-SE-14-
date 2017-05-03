#include <iostream>
#include <fstream>
#include <string>
#include "Converter.hxx"

class ConverterGroup{

	private:
		std::vector<Converter*> listOfConverters;
	public:
	
	//constructor
	ConverterGroup();

	//Destructor
	virtual ~ConverterGroup();

	//Methods
	void add(const std::string tipus);

};
