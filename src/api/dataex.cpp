#include "dataex.h"
#include <iostream>
#include <string>

friends::friends(): friends("",""){}

friends::friends(std::string names, std::string picurls) : name_(names), picurl_(picurls){}

std::string friends::names() const{return name_;}

std::string friends::picurls() const{return picurl_;}
