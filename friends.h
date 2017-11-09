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

Friends::Friends(): Friends("",""){
    
}

Friends::Friends(std::string names, std::string picurls) : name_(names), picurl_(picurls){}


void Friends::setNames(std::string fname){
    
    name_ = fname;
}

std::string Friends::getNames() const{
    return name_;
}

std::string Friends::getPicUrls() const{
    return picurl_;
}

std::string Friends::genRandom(){
    return friends[rand() % stringLength];
}

bool Friends::compareNames(std::string random, std::string guess) const{
    
    std::transform(random.begin(), random.end(), random.begin(), ::toupper);
    std::transform(guess.begin(),guess.end(), guess.begin(), ::toupper);
    
    
    if(guess == random){
        std::cout << "Yep. Thats right." << std::endl;
        return true;
    }
    else{
        std::cout << "Nope. Thats not right." <<std::endl;
        return false;
    }
    
}


#endif
