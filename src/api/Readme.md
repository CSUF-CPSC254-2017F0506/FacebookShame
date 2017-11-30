# Required libraries
The api files require a couple of libraries to run; specifically webkitgtk2 and cpprest. You can install the necessary files by using the commands below.

## Ubuntu
    sudo apt-get install libwebkit2gtk-4.0-dev libcpprest-dev

# Compilation
You will need to make sure that the compiler has access to the libraries when you compile the code. Below is an example showing how you might link the libraries to compile a file called driver.cpp that contains code utilizing the api

    g++ driver.cpp -o driver -std=c++11 -lboost_system -lcrypto -lssl -lcpprest `pkg-config gtkmm-3.0 webkit2gtk-4.0 --cflags --libs`

# Known Issues
If for some reason there is an emoji present in your facebook data the JSON would not be able to extract it and return an error.

# Incorporating the program
Include the following into your main cpp

	#include <vector>
	#include "friends.h"
	#include "driver.h"

If you would like to see an example of this, then take a look at main.cpp above.

Make sure you compile the program using the following:

	g++ src/api/oauth2.cpp src/api/driver.cpp friends.cpp -o driver -std=c++11 -lboost_system -lcrypto -lssl -lcpprest -lsqlite3 `pkg-config gtkmm-3.0 webkit2gtk-4.0 --cflags --libs`

Plus any other files that you may need to add.

## Calling the function
Simply call the function callFacebook(); to run the program. This function will return a vector that has the information from facebook. A way to take advantage of this would be:

	std::vector<friends> info;
	info = callFacebook();

"info" will now have the proper information.

## Accessing Data
The data is stored in a vector of classes. In this class you can access the following:

	getNames(): will return the first and last name of the friend
	getPicUrls():will return the url of the friends picture
	getId():will return the facebokk id of the friend

So if the vector is called "info" then to get the name of a freind you would try something like the following

	info[i].getNames();
	info[i].getPicUrls();
	info[i].getId();

