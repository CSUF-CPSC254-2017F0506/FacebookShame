#include <iostream>
#include <vector>
#include "../../friends.h"
#include "driver.h"

int main()
{
	std::vector<Friends> info = callFacebook();
	std::cout<<"I have called the function callFacebook() which returns a vector full of the information from facebook\n";
	
	for(int i = 0; i< info.size(); i++)
	{
		std::cout << i << ": " << info[i].getNames() << std::endl << "     Url: " << info[i].getPicUrls() << std::endl << 				"      Id: "<< info[i].getId() << std::endl;
	}
	return 0;
}
