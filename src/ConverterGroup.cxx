#include "ConverterGroup.hxx"
#include "libLibreOffice2Html.hxx"

ConverterGroup::ConverterGroup(){

}

ConverterGroup::~ConverterGroup(){

}


void ConverterGroup::add(const std::string tipus){
	
}

void ConverterGroup::convert(const std::string &original, const std::string &converted){
		std::string converted2;
		converted2 = converted + " [multiple HTML files].war\0";
		int conversion = 0;
			std::ofstream newfile(converted2.c_str());
			conversion = OO_WarGeneration(original.c_str(),converted2.c_str());
}