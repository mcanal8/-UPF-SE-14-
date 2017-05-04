#include "ConverterGroup.hxx"


ConverterGroup::ConverterGroup(){

}

ConverterGroup::~ConverterGroup(){

}


void ConverterGroup::add(const std::string tipus){
	if ( tipus.compare("html") == 0){
		Converter* converterHtml;
		converterHtml = new  HtmlConverter();
		
		listOfConverters.push_back( converterHtml );
	}
}

void ConverterGroup::convert(const std::string &original, const std::string &converted){
	if (listOfConverters.size() > 0)	
		listOfConverters[0]->convert( original, converted);
	else;

}
