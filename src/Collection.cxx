#include <iostream>
#include <cstring>

class Collection{
	public:
	virtual std::string title(std::string a = "-- Untitled --"){
		return a;
	}
};
