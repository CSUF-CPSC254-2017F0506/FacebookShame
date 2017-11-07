#include <cpprest/http_client.h>
#include <cpprest/uri.h>  
#include "oauth2.h"
#include <iostream>

using namespace web; 
using namespace web::http;
using namespace web::http::client; 

void callme(std::string param, std::string value){
  http_client client(U("https://graph.facebook.com/v2.10"));
  uri_builder builder(U("/me/friends?fields=picture.width(1000).height(700),name"));
	builder.append_query(U("access_token"), value);

  pplx::task<void> requestTask = client.request(methods::GET, builder.to_string()).then([] (http_response response){
		json::array data = response.extract_json().get().at(U("data")).as_array();
		for(int i=0; i<data.size(); i++){	
			std::string name = data[i].at(U("name")).as_string();
			json::object picture = data[i].at(U("picture")).as_object();
			json::object dataurl = picture.at(U("data")).as_object();
			std::string url = dataurl.at(U("url")).as_string();
			std::cout << "name: " << name << std::endl;
			std::cout << "url: " << url << std::endl;
		}
  });
  requestTask.wait();
}

int main(){
	uri_builder login("https://www.facebook.com/v2.10/dialog/oauth");
	login.append_query("client_id", 125649754768050);
	login.append_query("response_type", "token");
	login.append_query("scope", "user_posts");
	login.append_query("redirect_uri", "https://www.facebook.com/connect/login_success.html");

	OAuth2 auth(login.to_string(), "access_token");
	auth.setCallback(callme);
	auth.init();
	return 0;
}
