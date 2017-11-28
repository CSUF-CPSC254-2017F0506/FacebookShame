#include <gtkmm.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "/home/cpsc254/FacebookShame/src/api/dataex.h"
#include "/home/cpsc254/FacebookShame/src/api/driver.h"

void set_high_score();//from database
void convert();//allow picture to show
void curr_win_poss();//keeps window location
string get_screen_name();//for database
string get_ran_per();//from api
int get_score();

void on_button_clicked();//login
void on_button_clicked2();//quit
void on_button_clicked3();//submit guess
void on_button_clicked4();//on continue

void convert(){
pTextbox3->set_text("Firstname\tLastname");
string str = "wget -O temp.jpg -U Mozilla '";
str += get_ran_per();
str += "' --header Cookie: 'allow-download=1'";
const char * url = str.c_str();
system(url);
pImage ->set("temp.jpg");
}

string get_ran_per(){//this func will pick a random person from vector

int total = info.size();
srand(time(NULL));
pick = rand() % total;
cout<<"pick: "<<pick<<"\ttotal: "<<total<<endl;
url = info[pick].picurls();
return url;

}

string get_screen_name(){
string tempname;
tempname = pTextbox->get_text();
return tempname;
}

void set_high_score(){
//call func 
//set high score to stored high score 
}

void curr_win_poss(){//save window position
int x,y;
//pWindow->get_position(x,y);
if(pWindow->get_visible() == true){
pWindow->get_position(x,y);
}
else if(pWindow2->get_visible() == true){
pWindow2->get_position(x,y);
}
else if(pWindow3->get_visible() == true){
pWindow3->get_position(x,y);
}
else if(pWindow4->get_visible() == true){
pWindow4->get_position(x,y);
}
pWindow->move(x,y);
pWindow2->move(x,y);
pWindow3->move(x,y);
pWindow4->move(x,y);
}

int get_score(){
return score;
}

void on_button_clicked(){//login
curr_win_poss(); 
pWindow->hide();
info = callFacebook();
	std::cout<<"I have called the function callFacebook() which returns a vector full of the information from facebook\n";
	
	for(int i = 0; i< info.size(); i++)
	{
		std::cout << i << ": " << info[i].names() << std::endl << "     Url: " << info[i].picurls() << std::endl << 				"      Id: "<< info[i].ids() << std::endl;
	}
	
//run the fb login driver

convert();



pWindow2->show();

cout<<get_screen_name()<<endl;
}

void on_button_clicked2(){//quit

pWindow->hide();
pWindow2->hide();
pWindow3->hide();
pWindow4->hide();
Gtk::Main::quit();
}

void on_button_clicked3(){//guess
curr_win_poss();
pWindow2->hide();
if(pTextbox3->get_text() == info[pick].names()){ //names of random picked per
//database has a check function
score++;
std::cout << score <<"\n"<<std::flush;
pWindow4->show(); 
}
else{
currscore = pLabel->get_text(); 
currscore += std::to_string(score);
pLabel->set_text(currscore);
cout <<currscore <<endl;
pWindow3->show(); 
}
}

void on_button_clicked4(){//cont
curr_win_poss();
pWindow4->hide();
convert();
pWindow2->show();
}

