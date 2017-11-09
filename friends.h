//
//  friends.h
//  FacebookShame
//
//  Created by Zulema Perez

#ifndef friends_h
#define friends_h

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>


static std::vector<std::string> friends ;

size_t stringLength = friends.size();

class Friends{
public:
    Friends();
    Friends(std::string,std::string);
    
    void setNames(std::string fname);
    std::string getNames( ) const;
    
    void setPicUrls();
    std::string getPicUrls() const;
    
    std::string genRandom();
    
    bool compareNames(std::string, std::string) const;
    
    
private:
    std::string name_;
    std::string picurl_;
};


#endif
