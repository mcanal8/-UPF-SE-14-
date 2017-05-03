#include <iostream>
#include <fstream>
#include <string>
#include "Converter.hxx"

class HtmlConverter : public Converter{

	private:

	public:
	
	//constructor
	HtmlConverter();

	//Destructor
	~HtmlConverter();

	//Methods
	void convert(const std::string &original, const std::string &converted);

};
