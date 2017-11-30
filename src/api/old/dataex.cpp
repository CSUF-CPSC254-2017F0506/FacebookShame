#include "dataex.h"
#include <iostream>
#include <string>

friends::friends(): friends("","", ""){}

friends::friends(std::string names, std::string picurls, std::string ids) : name_(names), picurl_(picurls), id_(ids){}

std::string friends::names() const{return name_;}

std::string friends::picurls() const{return picurl_;}

std::string friends::ids() const{return id_;}
