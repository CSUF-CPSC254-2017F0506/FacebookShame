# Required libraries
The api files require a couple of libraries to run; specifically webkitgtk2 and cpprest. You can install the necessary files by using the commands below.

## Ubuntu
    sudo apt-get install libwebkit2gtk-4.0-dev libcpprest-dev

# Compilation
You will need to make sure that the compiler has access to the libraries when you compile the code. Below is an example showing how you might link the libraries to compile a file called driver.cpp that contains code utilizing the api

    g++ driver.cpp -o driver -std=c++11 -lboost_system -lcrypto -lssl -lcpprest `pkg-config gtkmm-3.0 webkit2gtk-4.0 --cflags --libs`

# Known Issues
If for some reason there is an emoji present in your facebook data the JSON would not be able to extract it and return an error.

# Accessing Data
The data is stored in a list of classes. In this class you can access the following:

	names(): will return the first and last name of the friend
	picurls():will return the url of the friends picture

The front of the list will always have the name of the actual user. he will not have a picture url but you would still be able to call it. In this case the picture url would return an empty string.
