#makefile

main: main.cpp ../friends.cpp ../src/api/oauth2.cpp ../src/api/driver.cpp ../player.cpp
	g++ ../src/api/oauth2.cpp ../friends.cpp ../src/api/driver.cpp ../player.cpp main.cpp -o main -std=c++11 -lboost_system -lcrypto -lssl -lcpprest -lsqlite3 `pkg-config gtkmm-3.0 webkit2gtk-4.0 --cflags --libs`

clean:
	rm main
