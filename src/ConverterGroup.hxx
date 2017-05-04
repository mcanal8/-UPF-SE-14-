#include <iostream>
#include <fstream>
#include <string>
#include "Converter.hxx"
#include <vector>

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
	void convert(const std::string &original, const std::string &converted);

};
