#include "Work.hxx"

Work::Work(){
		a = "-- Untitled --";
		isbn_num = (-1);	
		original = "";
		texto = "";	
		//topicsOfWork = "";
		
	}
	Work::~Work(){
		int i;
		
		for(i = 0; i < TopicsOfaWork.size(); i++){
			if(TopicsOfaWork[i]){
				delete TopicsOfaWork[i];
			}
		}
	}
	
	string Work::title(){
		return a;	// Retorna el titol del work seleccionat
	}
	void Work::title(string stringTitle){
		a = stringTitle;	// Modifica el titol del work seleccionat
 	}
	int Work::isbn(){
		return isbn_num;	// Retorna ISBN del work seleccionat
	}
	void Work::isbn(int nou_ISBN){
		isbn_num = nou_ISBN;	// Modifica el ISBN del work seleccionat
 	}
	string Work::originalFile(){
		return original;	//Retorna l'originalFile d'un work seleccionat
	}
	void Work::originalFile(string new_original){
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
		else 	texto = s+", '"+a+"',"+" 'originals/"+original+"'"; 
		
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
		for(int i = 0; i < TopicsOfaWork.size(); i++){
			returnString = returnString + TopicsOfaWork[i]->getName();
		}
		return returnString;
		
	}
