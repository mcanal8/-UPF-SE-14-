#include "PdfConverter.hxx"
#include "libLibreOffice2Pdf.hxx"
#include "fileException.hxx"


	//This function is the constructor of the class
	PdfConverter::PdfConverter(){
		watermark_state = false;

	}

	//This function is the destructor of the class
	PdfConverter::~PdfConverter(){

	}

void PdfConverter::convert(const std::string &original, const std::string &converted){
		std::string converted2;
		if(watermark_state){

			converted2 = converted + " [watermark].pdf";
		}
		else{
			converted2 = converted + " [printable].pdf";
		}
		
		try{

			LibreOfficeTools::convertToPdf(original,converted2,watermark);

		}
		catch (...){

				throw fileException();
		}	
		
}
void PdfConverter::activateWatermark(const std::string newWatermark){
		watermark_state = true;
		watermark = newWatermark;

}	
