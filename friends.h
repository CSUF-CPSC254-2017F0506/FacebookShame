//
//  friends.h
//  FacebookShame
//
//  Created by Zulema Perez

#ifndef friends_h
#define friends_h

#include <sqlite3.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>


std::vector<std::string> friends;

size_t stringLength = friends.size();

class Friends{
public:
    Friends();
    Friends(size_t id, std::string name, std::string picurl);
    
    void setId(size_t id);
    size_t getId();

    void setNames(std::string fname);
    std::string getNames( ) const;
    
    void setPicUrls(std::string pic);
    std::string getPicUrls() const;
    
    std::string genRandom();
    
    bool compareNames(std::string random, std::string guess);

    void insertBlob();
	
    void retrieveBlob();

    void deleteBlob();

    friend int callback(void* data, int argc, char** argv, char** azColName);
    
private:
    std::string name_;
    std::string picurl_;
    size_t id_;
};


#endif
