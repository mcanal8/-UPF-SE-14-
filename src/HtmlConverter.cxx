#include "HtmlConverter.hxx"
#include "libLibreOffice2Html.hxx"
#include "fileException.hxx"


	//This function is the constructor of the class
	HtmlConverter::HtmlConverter(){

	}

	//This function is the destructor of the class
	HtmlConverter::~HtmlConverter(){

	}

void HtmlConverter::convert(const char* original, std::string converted){

		converted.append(" [multiple HTML files].war");
		char* convertedChar = new char[converted.size() + 1];
		std::copy(converted.begin(), converted.end(), convertedChar);
		convertedChar[converted.size()] = '\0'; 
		char* convertedName[]= {convertedChar, 0
		};
		int conversion;
		//std::fstream fs;
		for(int i = 0; convertedName[i]; ++i)
		{
			std::ofstream newfile(convertedName[i]);
			conversion = OO_WarGeneration(original,convertedName[i]);	
			/*fs.open(convertedName[i], std::ios::app);
			fs << "War file generated from ‘originals/Original.odt’\n";
			fs.close();*/
		}
		delete[] convertedChar;
		if(conversion == -1)
			throw fileException();
	}	
