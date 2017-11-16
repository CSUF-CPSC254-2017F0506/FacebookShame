#include <iostream>
#include <vector>
#include "dataex.h"
#include "driver.h"

int main()
{
	std::vector<friends> info = callFacebook();
	std::cout<<"I have called the function callFacebook() which returns a vector full of the information from facebook\n";
	
	for(int i = 0; i< info.size(); i++)
	{
		std::cout << i << ": " << info[i].names() << std::endl << "     Url: " << info[i].picurls() << std::endl << 				"      Id: "<< info[i].ids() << std::endl;
	}
	return 0;
}
