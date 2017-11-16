
#include "friends.h"
#include "src/api/oauth2.h"
#include <cpprest/http_client.h>
#include <cpprest/uri.h>  
#include <vector> 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>

using namespace web; 
using namespace web::http;
using namespace web::http::client; 

std::vector <Friends> flist;

Friends::Friends(): Friends("","",""){}

Friends::Friends(std::string name, std::string picurl, std::string id) : name_(name), picurl_(picurl), id_(id){}


void callme(std::string param, std::string value){
  http_client client(U("https://graph.facebook.com/v2.10"));
  uri_builder builder(U("/me?fields=name,friends%7Bpicture.width(159).height(127),name,id%7D"));
	builder.append_query(U("access_token"), value);

  pplx::task<void> requestTask = client.request(methods::GET, builder.to_string()).then([] (http_response response){

		//std::string username = response.extract_json().get().at(U("name")).as_string;
		//std::cout<< username;
			json::object finfo = response.extract_json().get().at(U("friends")).as_object();
			json::array data = finfo.at(U("data")).as_array();
		
		for(int i=0; i<data.size(); i++){	
			std::string name = data[i].at(U("name")).as_string();
			json::object picture = data[i].at(U("picture")).as_object();
			json::object dataurl = picture.at(U("data")).as_object();
			std::string url = dataurl.at(U("url")).as_string();
			std::string id = data[i].at(U("id")).as_string();
			Friends flisttemp(name, url,id);
			flist.push_back(flisttemp);

			
			//std::cout << "name: " << flist[i].names() << std::endl;
			//std::cout << "url: " << flist[i].picurls() << std::endl;
			//std::cout << "id: " << flist[i].ids() << std::endl;
		}
		//friends usert(username, "");
		//flist.push_front(usert);

  });
  requestTask.wait();
}

std::vector<Friends> callFacebook(){
	uri_builder login("https://www.facebook.com/v2.10/dialog/oauth");
	login.append_query("client_id", 125649754768050);
	login.append_query("response_type", "token");
	login.append_query("scope", "user_posts");
	login.append_query("redirect_uri", "https://www.facebook.com/connect/login_success.html");
	OAuth2 auth(login.to_string(), "access_token");
	auth.setCallback(callme);
	auth.init();
	//std::cout <<"\nThe data is now stored in a vector of classes, the front of this vector has: " 
	//	  << flist.front().names() << " " << flist.front().picurls() << std::endl;
	return flist;
}

std::vector <Friends> friends = callFacebook();

void Friends::setId(std::string id){
	id_= id;
}

std::string Friends::getId(){
csu	return id_;
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

int Friends::genRandom(){

	
	int i =0; 
    for(; i < friends.size(); i++){
		std::cout <<i<<" " << friends[i].getNames() << std::endl << " "<< friends[i].getPicUrls()<< std::endl << " "<< friends[i].getId()<<std::endl;
    }

    return rand() % i;
    
}

bool Friends::compareNames(std::string random, std::string guess){
    
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



