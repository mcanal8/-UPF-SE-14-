#include <string>
#include <iostream>

class Work{
	private:
	std::string a;
	
	public:
	
	virtual void title(std::string message){
		
	}

	//constructor
	Work();

	//Methods
	std::string title();
};

Work::Work(){
		a = "-- Untitled --";		
	}
	
	std::string Work::title(){
		return a;
	}
	
