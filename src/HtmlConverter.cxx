#include "HtmlConverter.hxx"


	//This function is the constructor of the class
	HtmlConverter::HtmlConverter(){

	}

	//This function is the destructor of the class
	HtmlConverter::~HtmlConverter(){

	}

void HtmlConverter::convert(const std::string original, const std::string converted){
		const char* convertedName[]= {"generated/Prefix [multiple HTML files].war", 0
		};
		for(int i = 0; convertedName[i]; ++i)
			std::ofstream newfile(convertedName[i]);
	
}
