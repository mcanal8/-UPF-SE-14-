#include "Author.hxx"
#include "myexception.hxx"

Author::Author(){
	_name = "--A_Name--";
	_contracted = false;
	_catalogue = "";
	_stringnum = "";
	//listOfWorks[= (Work*) malloc(sizeof(Work));
	_comptador = 0;
	status = "";
}

//Added in First test
std::string Author::getName(){
	
	return _name;
	
}

//Added in Second test
void Author::setName(std::string newname){
	
	_name = newname;
}

//Added in third test
bool Author::isContracted(){
	return _contracted;
}

//Added in fourth test
void Author::contract(){
	status = " [contracted]\n";
	_contracted = true;
}
std::string Author::catalogue(){//Retorna el cataleg de l'Autor corresponent.
		return _catalogue;
	}

//Added in P3 Test 2
void Author::addWork(std::string workname, int worknum, std::string file){
	/*//COM QUE EL NOSTRE COMPILADOR NO DETECTA EL TOSTRING(), HEM DE FER SERVIR AIXO PER PASAR A STRING	
	//convert int worknum to string worknum	
	std::string s;	
	std::stringstream out;
	out << worknum;
	//s is string worknum (converted)
	s = out.str();*/
	
	Work newWork = Work();
	newWork.title(workname);
	newWork.isbn(worknum);
	newWork.originalFile(file);
	
	//listOfWorks = (Work*) realloc(listOfWorks,sizeof(Work));
	listOfWorks[_comptador]= newWork;
	_comptador++;
	_catalogue = _catalogue.append("\t"+ newWork.aText()+"\n");//Amb la funció append afegim al final de l'string _catalogue el nou text
	
}
//Added in P3 test 4
Work& Author::findWork(std::string workname){
	int i = 0;
	Work work_selected;
	for (i = 0;i<=_comptador;++i){
		if(workname.compare(listOfWorks[i].title()) == 0)	work_selected = listOfWorks[i];	
	}
	if(work_selected.title().compare(workname) != 0){
		throw myexception(); //myexception.hxx Added in P3 test 5
	}
	Work& to_return = work_selected; 
	return to_return;
	
}
//Added in P3 test 6
void Author::name(std::string inserted_name){
	setName(inserted_name);
	status =" [external]\n";
	
}
std::string Author::description(){
	std::string description = "";
	if(_contracted == true){
		description = description.append(getName() + status + catalogue());

			/*"An author [contracted]\n"
			"\t111, 'A work', 'originals/aFile.odt'\n"
			"\t222, 'Another work', 'originals/anotherFile.odt'\n";*/
	}
	else	description = description.append(getName() + status);	//"An author [external]\n";
	return description;
	
}






