#ifndef DATAEX_H
#define DATAEX_H


#include <list>
#include <string>

class friends
{
	public:
		friends(std::string,std::string);
		std::string names() const;
		std::string picurls() const;
		//void setname(std::string);
		//void setpicurl(std::string);
	private:
		std::string name_;
		std::string picurl_;
};

#endif
