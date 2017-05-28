#include <string>

using namespace std;

class Channel{

	private:
		string _name;
		string _description;
		string _link;

	public:
	//Constructor
	Channel();

	//Destructor
	~Channel();

	//Methods
	void addChannel(const string name, const string description);
	string getChannel();
	string getName();
	string getLink();
};


