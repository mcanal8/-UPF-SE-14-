#include "PdfConverter.hxx"
//#include "libLibreOffice2Html.hxx"
//#include "fileException.hxx"


	//This function is the constructor of the class
	PdfConverter::PdfConverter(){
		watermark_state = false;

	}

	//This function is the destructor of the class
	PdfConverter::~PdfConverter(){

	}

void PdfConverter::convert(const char* original, std::string converted){
		if(watermark_state){
			converted.append( " [watermark].pdf" );
		}
		else{
			converted.append(" [printable].pdf");
		}
		char* convertedChar = new char[converted.size() + 1];
		std::copy(converted.begin(), converted.end(), convertedChar);
		convertedChar[converted.size()] = '\0'; 
		char* convertedName[]= {convertedChar, 0
		};

 		for(int i = 0; convertedName[i]; ++i){
 			std::ofstream newfile(convertedName[i]);
 		}

		delete[] convertedChar;

}
void PdfConverter::activateWatermark(const std::string newWatermark){
		watermark_state = true;
		watermark = newWatermark;

}	
