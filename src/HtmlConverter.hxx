#include <iostream>
#include <fstream>
#include <string>
#include "libLibreOffice2Html.hxx"

#ifndef Converterclass
#define Converterclass
	#include "Converter.hxx"
#endif




class HtmlConverter : public Converter{

	private:

	public:
	
	//constructor
	HtmlConverter();

	//Destructor
	~HtmlConverter();

	//Methods
	void convert(const std::string &original, const std::string &converted);
	void activateWatermark(const std::string newWatermark); //Es para el polimorfismo

};
