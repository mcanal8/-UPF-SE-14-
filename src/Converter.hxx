#include <iostream>
#include <fstream>
#include <string>



class Converter{

	private:

	public:
	
	//constructor
	Converter();

	//Destructor
	virtual ~Converter();

	//Methods
	virtual	void convert(const std::string &original, const std::string &converted){};
	virtual void activateWatermark(const std::string newWatermark){}; //Tendremos que quitarlo;

};
