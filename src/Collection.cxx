
#include "Collection.hxx"

	Collection::Collection(){
		strcpy(a, "-- Untitled --");
		strcpy(stringTitle, "   ");
	}

	char Collection::title(char stringTitle){
		strcpy(a, (char*)stringTitle);
		return a;
	}
