#include "HtmlConverter.hxx"


	//This function is the constructor of the class
	HtmlConverter::HtmlConverter(){

	}

	//This function is the destructor of the class
	HtmlConverter::~HtmlConverter(){

	}

void HtmlConverter::convert(const std::string original, std::string converted){

		converted.append(" [multiple HTML files].war");
		char * convertedChar = new char[converted.size() + 1];
		std::copy(converted.begin(), converted.end(), convertedChar);
		convertedChar[converted.size()] = '\0'; 
		char* convertedName[]= {convertedChar, 0
		};
		for(int i = 0; convertedName[i]; ++i)
			std::ofstream newfile(convertedName[i]);
		delete[] convertedChar;
	}	
