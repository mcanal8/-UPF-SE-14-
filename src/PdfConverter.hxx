#include <iostream>
#include <fstream>
#include <string>

class PdfConverter{

	private:
		bool watermark_state;
		std::string watermark;

	public:
	
	//constructor
	PdfConverter();

	//Destructor
	~PdfConverter();

	//Methods
	void convert(const char* original, std::string converted);
	void activateWatermark(const std::string newWatermark);

};
