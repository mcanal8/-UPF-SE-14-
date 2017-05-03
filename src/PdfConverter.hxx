#include <iostream>
#include <fstream>
#include <string>
#include "Converter.hxx"



class PdfConverter : public Converter{

	private:
		bool watermark_state;
		std::string watermark;

	public:
	
	//constructor
	PdfConverter();

	//Destructor
	~PdfConverter();

	//Methods
	void convert(const std::string &original, const std::string &converted);
	void activateWatermark(const std::string newWatermark);

};
