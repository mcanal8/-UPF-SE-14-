#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HtmlConverter.hxx"
#include "PdfConverter.hxx"



class ConverterGroup{

	private:
		std::vector<Converter*> listOfConverters;
	public:
	
	//constructor
	ConverterGroup();

	//Destructor
	~ConverterGroup();

	//Methods
	void add(const std::string tipus);
	void convert(const std::string &original, const std::string &converted);

};
