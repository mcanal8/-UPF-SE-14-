#include "Channel.hxx"

Channel::Channel(){
	_name = "";
	_description = "";
}

Channel::~Channel(){
	
}

void Channel::addChannel(const string name, const string description){
	_name = name;
	_description = description;
}

string Channel::getChannel(){
	string returnString = "";
	returnString = _name + "\n" + "\t" + _description + "\n";
	return 	returnString;
}