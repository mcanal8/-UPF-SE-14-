#include "ConverterGroup.hxx"


ConverterGroup::ConverterGroup(){

}

ConverterGroup::~ConverterGroup(){
	unsigned int i;
		for(i = 0; i < listOfConverters.size(); i++){
			if(listOfConverters[i]){
				delete listOfConverters[i];
			}
		}
}


void ConverterGroup::add(const std::string tipus){
	if ( tipus.compare("html") == 0){
		Converter* converterHtml;
		converterHtml = new  HtmlConverter();
		
		listOfConverters.push_back( converterHtml );
	}
	/*if ( tipus.compare("pdf_print") == 0){
		Converter* converterPdf;
		converterPdf = new  PdfConverter();
		
		listOfConverters.push_back( converterPdf );
	}*/
}

void ConverterGroup::convert(const std::string &original, const std::string &converted){
	if (listOfConverters.size() > 0)	
		listOfConverters[0]->convert( original, converted);
	else;

}
