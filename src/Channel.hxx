#ifndef Channel_hxx
#define Channel_hxx

#include <string>
#include <vector>

using namespace std;

class Channel{

	private:
		string _name;
		string _description;
		string _link;
		string _itemName;
		string _itemAuthor;
		string _itemLink;
		/*typedef struct{
			string name;
			string author;
			string link;
		}item;*/
		//vector<item*> listOfItems;
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
	string getItemName();
	string getItemAuthor();
	string getItemLink();
	//svector<item*> getListOfItems();
	//item getItem();
};
#endif

