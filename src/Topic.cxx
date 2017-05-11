#include "Topic.hxx"






	//This function is the constructor of the class
	Topic::Topic(){

	}

	//This function is the destructor of the class
	Topic::~Topic(){

	}

	void Topic::setName(string newName){
		name = newName;
	}

	string Topic::getName(){
		return name;
	}