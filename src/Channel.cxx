#include "Channel.hxx"

Channel::Channel(){
	_name = "";
	_description = "";
	_link = "";

	items = false;
}

Channel::~Channel(){
	
	_itemName.clear();
	_itemAuthor.clear();
	_itemLink.clear();
		
}

void Channel::addChannel(const string name, const string description){
	_name = name;
	_description = description;
	_link = "http://www.meltingpotonline.com/" + name;
}

string Channel::getDescription(){
	string returnString = "";
	returnString = _name + "\n" + "\t" + _description + "\n";
	return 	_description;
}

string Channel::getName(){
	return _name;
}

string Channel::getLink(){
	return _link;
}

void Channel::update(const string workName, const string authorName){
	
	_itemName.push_back("'" + workName + "'");
	_itemAuthor.push_back( "'" + authorName + "'" );
	_itemLink.push_back("http://www.meltingpotonline.com/infoWork?author='" + authorName + "'&title='" + workName + "'");
	items = true;
}

bool Channel::itemsBool(){
	return items;
}

string Channel::getItemName(int i){
	return _itemName[i];
}

string Channel::getItemAuthor(int i){
	return _itemAuthor[i];
}

string Channel::getItemLink(int i){
	return _itemLink[i];
}
int Channel::getArraySizeOfChannelArrays(){
	return _itemName.size();
}


