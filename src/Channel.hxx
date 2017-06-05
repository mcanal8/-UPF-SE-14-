#ifndef Channel_hxx
#define Channel_hxx

#include <iostream>
#include <cstring>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>


using namespace std;

class Channel{

	private:
		string _name;
		string _description;
		string _link;
		//string _itemName;
		//string _itemAuthor;
		//string _itemLink;
		/*typedef struct{
			string name;
			string author;
			string link;
		}item;*/
		vector<string> _itemName;	//Amb vector<string*> donava segmentation fault.
		vector<string> _itemAuthor;
		vector<string> _itemLink;
		
		bool items;


	public:
	//Constructor
	Channel();

	//Destructor
	~Channel();

	//Methods
	void addChannel(const string name, const string description);
	string getDescription();
	string getName();
	string getLink();
	void update(const string workName, const string authorName);
	bool itemsBool();
	string getItemName(int i);
	string getItemAuthor(int i);
	string getItemLink(int i);
	int getArraySizeOfChannelArrays();
	//svector<item*> getListOfItems();
	//item getItem();
};
#endif

