/* 
   - usem els accessors d'escriptura i de lectura de l'atribut _nom

   En resum hem après:
   - com escriure per consola fent servir <iostream>
   - simbols de la libreria localitzats al namespace std::
   - les classes acaben en ;
   - el mètodes i atributs per defecte són private
   - com fer subclasses: "Sub : public Super"
   - perquè serveixen els mètodes virtuals
   - polimorfisme
   - usar #ifndef als headers per evitar redefinicions
   - pas de paràmetres per referència
   - col.leccions estàndars vector i list
   - typdefs
   - iteradors
   - std::string
   - ús d'accessors
 */
/*MODIFICAT PER AFEGIR LA TASCA QUE DEMANEN DESPRES DEL TUTORIAL*/

#include <list>
#include "animals.hxx"
#include <stdio.h> //(TASCA A AFEGIR)

typedef std::list<Animal*> Animals;

int main(void)
{
	Animals animals;
	//afegim llistes per a cada recinte del zoo (TASCA A AFEGIR)
	Animals especieIndefinida;
	Animals elefants;
	Animals granotes;
	Animals gats;
	// introduïm un animal de cada tipus
	Animal unAnimal;
	unAnimal.nom("Pikatxu");
	animals.push_back(&unAnimal);
	//afegim a llista de sector altres (TASCA A AFEGIR)
	especieIndefinida.push_back(&unAnimal);

	Elefant unElefant;
	unElefant.nom("Jumbo l'Orellut");
	animals.push_back(&unElefant); 
	//afegim a llista de sector elefants (TASCA A AFEGIR)
	elefants.push_back(&unElefant);

	Granota unaGranota;
	unaGranota.nom("Gustavo el Reporter");
	animals.push_back(&unaGranota);
	//afegim a llista de sector granotes (TASCA A AFEGIR)
	granotes.push_back(&unaGranota);

	Gat unGat;
	unGat.nom("Gat Amb Botes");
	animals.push_back(&unGat);
	//afegim a llista de sector gats (TASCA A AFEGIR)
	gats.push_back(&unGat);


	// iterem fent servir iteradors
	for (Animals::iterator it=animals.begin(); it!=animals.end(); it++)
	{
		std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
		(*it)->escriuEspecie();
		
			
	}
	//menu del programa (TASCA A AFEGIR)
	int opcio_menu_principal = 0;
	int opcio_menu_secundari = 0;
	while(opcio_menu_principal != 2){
		std::cout << "\nMENU PRINCIPAL DEL PROGRAMA:\n" << std::endl;
		std::cout << "		1 - Consultar enclosure \n" << std::endl;
		std::cout << "		2 - Sortir del programa\n" << std::endl;
		printf("\nTriar opció (1 o 2): ");
		scanf("%d",&opcio_menu_principal);
		if(opcio_menu_principal == 1){
			while(opcio_menu_secundari != 5){
				std::cout << "\nMENU DE SECCIONS DEL ZOO:\n" << std::endl;
				std::cout << "		1 - Elefants \n" << std::endl;
				std::cout << "		2 - Granotes\n" << std::endl;
				std::cout << "		3 - Gats\n" << std::endl;	
				std::cout << "		4 - Altres(Especie indefinida)\n" << std::endl;
				std::cout << "		5 - Tornar al menu principal(ENRRERE)\n" << std::endl;
				printf("\nTriar opció (1,2,3,4 o 5): ");
				scanf("%d",&opcio_menu_secundari);
				if(opcio_menu_secundari == 1){
					std::cout << "\nHas triat la opció 1.\n\nPertanyen al sector de Elefants els següents animals: " << std::endl;
					for (Animals::iterator it=elefants.begin(); it!=elefants.end(); it++)
					{
						std::cout << "	- l'animal anomenat " << (*it)->nom()<<"\n";		
					}
				}
				else if(opcio_menu_secundari == 2){
					std::cout << "\nHas triat la opció 2.\n\nPertanyen al sector de Granotes els següents animals: " << std::endl;
					for (Animals::iterator it=granotes.begin(); it!=granotes.end(); it++)
					{
						std::cout << "	- l'animal anomenat " << (*it)->nom()<<"\n";		
					}
				}
				else if(opcio_menu_secundari == 3){
					std::cout << "\nHas triat la opció 3.\n\nPertanyen al sector de Gats els següents animals: " << std::endl;
					for (Animals::iterator it=gats.begin(); it!=gats.end(); it++)
					{
						std::cout << "	- l'animal anomenat " << (*it)->nom()<<"\n";		
					}
				}
				else if(opcio_menu_secundari == 4){
					std::cout << "\nHas triat la opció 4.\n\nPertanyen al sector de Altres els següents animals: " << std::endl;
					for (Animals::iterator it=especieIndefinida.begin(); it!=especieIndefinida.end(); it++)
					{
						std::cout << "	- l'animal anomenat " << (*it)->nom()<<"\n";		
					}
				}
				else if(opcio_menu_secundari == 5){
					std::cout << "\nHas triat tornar al menu anterior.\n\n" << std::endl;
				}
				else{
					std::cout << "\nOpció incorrecte, tria una opció del llistat.\n\n" << std::endl;
				}
				
			}
		}
		else if(opcio_menu_principal == 2){
			std::cout << "\nHas triat sortir del programa.\n" << std::endl;
		}
		else{
			std::cout << "\nOpció incorrecte, tria una opció del llistat.\n" << std::endl;
		}	
	}

	return 0;
}


