#include "Channel.hxx"

Channel::Channel(){
	_name = "";
	_description = "";
	_link = "";
}

Channel::~Channel(){
	
}

void Channel::addChannel(const string name, const string description){
	_name = name;
	_description = description;
	_link = "<link>http://www.meltingpotonline.com/" + name + "</link>\n";
}

string Channel::getChannel(){
	string returnString = "";
	returnString = _name + "\n" + "\t" + _description + "\n";
	return 	returnString;
}

string Channel::getName(){
	return _name;
}

string Channel::getLink(){
	return _link;
}