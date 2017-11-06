#include <cpprest/http_client.h>
#include <cpprest/uri.h>   
#include <iostream>

using namespace web; 
using namespace web::http;
using namespace web::http::client; 

int main(){
	http_client client(U("https://jsonplaceholder.typicode.com"));


  uri_builder builder(U("/posts"));
  builder.append_query(U("q"), U("cpprestsdk github"));
	std::cout << builder.to_string();
  pplx::task<void> requestTask = client.request(methods::GET, builder.to_string()).then([](http_response response){
			//std::cout << response.extract_json().get().c_str();
			//return response.extract_json();
			std::cout << response.extract_json().get().as_array()[0];
	});
	requestTask.wait();
}
