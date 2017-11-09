#include "dataex.h"
#include <iostream>
#include <string>

friends::friends(std::string names="\0", std::string picurls="\0") : name_(names), picurl_(picurls){}

std::string friends::names() const{return name_;}

std::string friends::picurls() const{return picurl_;}
