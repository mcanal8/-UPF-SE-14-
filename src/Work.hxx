#include <string>
#include <iostream>

class Work
{
public:
	
	virtual std::string title(std::string a ="-- Untitled --"){
			return a;
		}
};
