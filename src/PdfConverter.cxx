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
			//converted.append( " [watermark].pdf" );
			const char* convertedName[]= {"generated/Prefix [watermark].pdf", 0
			};

			for(int i = 0; convertedName[i]; ++i)

				std::ofstream newfile(convertedName[i]);
			}
		else{
			//converted.append("  [printable].pdf");

			const char* convertedName[]= {"generated/Prefix [printable].pdf", 0
			};
			for(int i = 0; convertedName[i]; ++i)
				std::ofstream newfile(convertedName[i]);
		}


}
void PdfConverter::activateWatermark(const std::string newWatermark){
		watermark_state = true;
		watermark = newWatermark;

}	
