#makefile

main: main.cpp /home/cpsc254/FacebookShame/src/api/driver.cpp /home/cpsc254/FacebookShame/src/api/oauth2.cpp
	g++ /home/cpsc254/FacebookShame/src/api/oauth2.cpp /home/cpsc254/FacebookShame/src/api/dataex.cpp /home/cpsc254/FacebookShame/src/api/driver.cpp main.cpp -o main -std=c++11 -lboost_system -lcrypto -lssl -lcpprest `pkg-config gtkmm-3.0 webkit2gtk-4.0 --cflags --libs`

clean:
	rm main
