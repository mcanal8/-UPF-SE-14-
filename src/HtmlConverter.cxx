#include "HtmlConverter.hxx"
#include "libLibreOffice2Html.hxx"
#include "fileException.hxx"


	//This function is the constructor of the class
	HtmlConverter::HtmlConverter(){

	}

	//This function is the destructor of the class
	HtmlConverter::~HtmlConverter(){

	}

void HtmlConverter::convert(const std::string &original, const std::string &converted){

		//cout << converted << "\n";
		std::string converted2;
		converted2 = converted + " [multiple HTML files].war\0";
		//cout << converted2 << "\n";
		int conversion = 0;
		//std::fstream fs;

			std::ofstream newfile(converted2.c_str());
			conversion = OO_WarGeneration(original.c_str(),converted2.c_str());

			printf("%d\n", conversion);
			/*fs.open(convertedName[i], std::ios::app);
			fs << "War file generated from ‘originals/Original.odt’\n";
			fs.close();*/
		if(conversion == -1)
			throw fileException();
	}	
