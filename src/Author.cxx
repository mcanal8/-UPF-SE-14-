#include "Author.hxx"
#include "workException.hxx"


Author::Author(){
	_name = "--A_Name--";
	_contracted = false;
	_catalogue = "";
	_stringnum = "";
	_comptador = 0;
	status = "";
}

Author::~Author(){
	unsigned int i;
	for(i = 0; i < listOfWorks.size(); i++){
		if(listOfWorks[i]){
			delete listOfWorks[i];
		}
	}
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
	
	Work *newWork = new Work();
	newWork->title(workname);
	newWork->isbn(worknum);
	newWork->originalFile(file);
	
	listOfWorks.push_back( newWork );
	_comptador++;
	_catalogue = _catalogue.append("\t"+ newWork->aText()+"\n");//Amb la funció append afegim al final de l'string _catalogue el nou text
	
	
}
//Added in P3 test 4
Work& Author::findWork(const std::string &workname){
	for (unsigned int i = 0;i < listOfWorks.size() ;++i){
		if(workname == listOfWorks[i]->title() )	
			return *listOfWorks[i];	
	}
	throw workException(); //workException.hxx Added in P3 test 5
}
//Added in P3 test 6+
void Author::name(std::string inserted_name){
	setName(inserted_name);
	status =" [external]\n";
	
}
std::string Author::description(){
	std::string description = "";
	description = description.append(getName() + status + catalogue());

			/*"An author [contracted]\n"
			"\t111, 'A work', 'originals/aFile.odt'\n"
			"\t222, 'Another work', 'originals/anotherFile.odt'\n";*/
	
	return description;
	
}

void Author::subscribeClient(Client* clientSelected){

	listOfClients.push_back(clientSelected);	//Canviat de variable client unica a llista de clients en un sol topic
}

void Author::notify(const std::string workName, const std::string authorName){
	for(int i = 0; i < listOfClients.size(); i++){ //Recorremos todo el vector de clientes suscritos y les notificamos
		listOfClients[i]->update(workName, authorName);
	}
}






