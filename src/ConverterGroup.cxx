#include "ConverterGroup.hxx"
#include "formatException.hxx"


//Constructor
ConverterGroup::ConverterGroup(){

}

//Destructor
ConverterGroup::~ConverterGroup(){
	unsigned int i;
		for(i = 0; i < listOfConverters.size(); i++){
			if(listOfConverters[i]){
				delete listOfConverters[i];
			}
		}
}

//Metodo para añadir una nueva conversion a la lista
void ConverterGroup::add(const std::string tipus){ 
	if ( tipus.compare("html") == 0){ 
		Converter *converterHtml;
		converterHtml = new  HtmlConverter();
		
		listOfConverters.push_back( converterHtml );
	}
	if ( tipus.compare("pdf_print") == 0){
		Converter *converterPdf;
		converterPdf = new  PdfConverter();
		
		listOfConverters.push_back( converterPdf );
	}
	if ( tipus.compare("pdf_mark") == 0){
		Converter *converterPdf;
		converterPdf = new  PdfConverter();
		converterPdf->activateWatermark("Watermark");
		listOfConverters.push_back( converterPdf );
	}
	if ( tipus.compare(".doc") == 0){ //Si se introduce otro tipo que no es pdf o html, salta una exception
		throw formatException();
	}
}

//Metodo para efectuar una conversion de la lista
void ConverterGroup::convert(const std::string &original, const std::string &converted){
	if (listOfConverters.size() > 0) //Antes de empezar la conversión miramos si hay elementos en la lista
		for(unsigned int i = 0; i < listOfConverters.size(); i++){
			listOfConverters[i]->convert( original, converted);
		}

}
