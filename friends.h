//
//  friends.h
//  FacebookShame
//
//  Created by Zulema Perez

#ifndef friends_h
#define friends_h
#include <iostream>
#include <string>

class Friends{
public:
    Friends();
    Friends(std::string name, std::string picurl, std::string id);
    
    void setId(std::string id);
    std::string getId();

    void setNames(std::string fname);
    std::string getNames( ) const;
    
    void setPicUrls(std::string pic);
    std::string getPicUrls() const;
    
    bool compareNames(std::string random, std::string guess);
    
private:
    std::string name_;
    std::string picurl_;
    std::string id_;
};

#endif
