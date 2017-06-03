#include "Channel.hxx"

Channel::Channel(){
	_name = "";
	_description = "";
	_link = "";
	_itemName = "";
	_itemAuthor = "";
	_itemLink = "";
	items = false;
}

Channel::~Channel(){
	
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
	string link;
	_itemName = "'" + workName + "'";
	_itemAuthor = "'" + authorName + "'";
	link = "http://www.meltingpotonline.com/infoWork?author=" + _itemAuthor + "&title=" + _itemName + "";
	_itemLink = link;
	items = true;
	//listOfItems.push_back(newItem);
}

bool Channel::itemsBool(){
	return items;
}

string Channel::getItemName(){
	return _itemName;
}

string Channel::getItemAuthor(){
	return _itemAuthor;
}

string Channel::getItemLink(){
	return _itemLink;
}

/*item Channel::getItem(){
	return newItem;
}*/
/*vector<item*> Channel::getListOfItems(){
	return listOfItems;
}*/
