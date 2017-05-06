#include <iostream>
#include <fstream>
#include <string>
#include "libLibreOffice2Pdf.hxx"

#ifndef Converterclass
#define Converterclass
	#include "Converter.hxx"
#endif


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
