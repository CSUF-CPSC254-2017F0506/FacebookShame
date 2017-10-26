#include "oauth2.h"
#include <iostream>

void callme(char* param, char* value){
  std::cout << "success parameter: " << param << std::endl << "access_token: " << value << std::endl << std::flush;
}

int main(){
	char* loginEndpoint = "https://www.facebook.com/v2.10/dialog/oauth?client_id=125649754768050&response_type=token&redirect_uri=https://www.facebook.com/connect/login_success.html";
	char* successParam = "access_token";
	OAuth2 auth(loginEndpoint, successParam);
	auth.setCallback(callme);
	auth.init();
	return 0;
}

