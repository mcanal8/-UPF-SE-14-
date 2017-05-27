#include <string>

using namespace std;

class Channel{

	private:
		string _name;
		string _description;

	public:
	//Constructor
	Channel();

	//Destructor
	~Channel();

	//Methods
	void addChannel(const string name, const string description);
	string getChannel();
};


