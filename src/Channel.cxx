#include "Channel.hxx"

Channel::Channel(){
	_name = "";
	_description = "";
	_link = "";
	//_itemName = "";
	//_itemAuthor = "";
	//_itemLink = "";
	items = false;
}

Channel::~Channel(){
	/*for(unsigned int i = 0; i < _itemName.size(); i++){
			//if(_itemName[i]){
				_itemName[i].clear();
			//}
	}
	for(unsigned int i = 0; i < _itemAuthor.size(); i++){
			//if(_itemAuthor[i]){
				_itemAuthor[i].clear;
			//}
	}
	for(unsigned int i = 0; i < _itemLink.size(); i++){
			//if(_itemLink[i]){
				_itemLink[i].clear;
			//}
	}*/
	/*int i = getArraySizeOfChannelArrays();
	_itemName.erase(_itemName.begin(),_itemName.begin() + i);
	_itemAuthor.erase(_itemAuthor.begin(),_itemAuthor.begin() + i);
	_itemLink.erase(_itemLink.begin(),_itemLink.begin() + i);*/
	_itemName.clear();
	_itemAuthor.clear();
	_itemLink.clear();
	// NO ESTIC SEGUR D'AIXO
	
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

/*item Channel::getItem(){
	return newItem;
}*/
/*vector<item*> Channel::getListOfItems(){
	return listOfItems;
}*/
