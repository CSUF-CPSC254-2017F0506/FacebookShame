#makefile

main: main.cpp ../src/api/driver.cpp ../src/api/oauth2.cpp
	g++ ../src/api/oauth2.cpp ../friends.cpp ../src/api/driver.cpp main.cpp -o main -std=c++11 -lboost_system -lcrypto -lssl -lcpprest `pkg-config gtkmm-3.0 webkit2gtk-4.0 --cflags --libs`

clean:
	rm main
