
#include "friends.h"
#include "src/api/driver.h"
#include <cpprest/http_client.h>
#include <cpprest/uri.h>  
#include <vector> 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace web; 
using namespace web::http;
using namespace web::http::client; 


Friends::Friends(): Friends("","",""){}

Friends::Friends(std::string name, std::string picurl, std::string id) : name_(name), picurl_(picurl), id_(id){}



std::vector <Friends> friends = callFacebook();

void Friends::setId(std::string id){
	id_= id;
}

std::string Friends::getId(){
	return id_;
}

void Friends::setNames(std::string fname){
    
    name_ = fname;
}

std::string Friends::getNames() const{

    return name_;
}

void Friends::setPicUrls(std::string pic){
	
	picurl_ = pic;
}

std::string Friends::getPicUrls() const{

    return picurl_;
}


bool Friends::compareNames(std::string random, std::string guess){
    
    
    random.erase(remove_if(random.begin(), random.end(), isspace));
    guess.erase(remove_if(guess.begin(), guess.end(), isspace));
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


