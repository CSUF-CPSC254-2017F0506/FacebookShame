
#include "friends.h"
#include <iostream>
#include <string>
#include <cstdlib>


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


