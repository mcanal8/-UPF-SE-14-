#include "Work.hxx"

Work::Work(){
		a = "-- Untitled --";
		isbn_num = (-1);	
		original = "";
		texto = "";	
		//textoTopic = "";
		
	}
	Work::~Work(){
		unsigned int i;
		
		for(i = 0; i < TopicsOfaWork.size(); i++){
			if(TopicsOfaWork[i]){
				delete TopicsOfaWork[i];
			}
		}
	}
	
	string Work::title(){
		return a;	// Retorna el titol del work seleccionat
	}
	void Work::title(const string & stringTitle){
		a = stringTitle;	// Modifica el titol del work seleccionat
 	}
	int Work::isbn() const{
		return isbn_num;	// Retorna ISBN del work seleccionat
	}
	void Work::isbn(const int nou_ISBN){
		isbn_num = nou_ISBN;	// Modifica el ISBN del work seleccionat
 	}
	string Work::originalFile(){
		return original;	//Retorna l'originalFile d'un work seleccionat
	}
	void Work::originalFile(const string  & new_original){
		original = new_original;	// Modifica l'originalFile del work seleccionat
	}
	string Work::aText(){ //Mostra toda la informacio d'un work determinat
		//convert int isbn to string isbn		
		string s;
		stringstream out;
		out << isbn();
		//s is isbn string converted
		s = out.str();
		
		//texto sera el siguiente (añadimos condicional para diferenciar cuando sea por defecto)
		if (isbn() == -1){
			texto = s+", '"+a+"',"+" '"+original+"'";
		}
		else 	texto = s+", '"+a+"',"+" 'originals/"+original+"'"+textoTopic; 
		
		return texto;
	}
	void Work::associateTopic(string newTopic){
		std::string topicStringName;
		topicStringName = newTopic;
		Topic *p_newTopic = new Topic();
		p_newTopic->setName(topicStringName);
		TopicsOfaWork.push_back(p_newTopic);
	}

	string Work::topics(){
		std::string returnString;
		
		for(unsigned int i = 0; i < TopicsOfaWork.size(); i++){
			if(TopicsOfaWork[i]->getName() != ""){			
				returnString = returnString + "\t\t'" + TopicsOfaWork[i]->getName() + "'\n";
			}
		}
		return returnString;
		
	}
