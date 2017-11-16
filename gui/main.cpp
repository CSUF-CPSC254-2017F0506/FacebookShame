#include <gtkmm.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
//vars
std::string name;
std::string Fname;
std::string Lname;
std::string urltemp;
std::string currscore;
int score = 0;

//funcs
void set_high_score();//from database
void convert();//allow picture to show
void curr_win_poss();//keeps window location
string get_screen_name();//for database
string get_ran_per();//from api
int get_score();


//login 
Gtk::Window* pWindow = nullptr;
Gtk::Entry* pTextbox = nullptr;
Gtk::Button* pButton = nullptr;
Gtk::Button* pButton2 = nullptr;

//gamescreen
Gtk::Window* pWindow2 = nullptr;
Gtk::Entry* pTextbox3 = nullptr;
Gtk::Entry* pTextbox4 = nullptr;
Gtk::Button* pButton3 = nullptr;
Gtk::Image* pImage = nullptr;
//fail
Gtk::Window* pWindow3 = nullptr;
Gtk::Button* pButton4 = nullptr;
Gtk::Button* pButton5 = nullptr;
Gtk::Label* pLabel = nullptr;
Gtk::Label* pLabel2 = nullptr;
//cont
Gtk::Window* pWindow4 = nullptr;
Gtk::Button* pButton6 = nullptr;
//button clicks
void on_button_clicked();//login
void on_button_clicked2();//quit
void on_button_clicked3();//submit guess
void on_button_clicked4();//on continue

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
  //auto app =  Gtk::Application::create(argc, argv);

  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("hello.glade");

  
//login
    
  builder->get_widget("hello_window", pWindow);
  pWindow->set_size_request(625,475);
  pWindow->set_resizable(false);

 
  builder->get_widget("entry1", pTextbox);
  pTextbox->set_text("screen_name");

  builder->get_widget("Login", pButton);  
  pButton->signal_clicked().connect( sigc::ptr_fun(on_button_clicked) );

  builder->get_widget("quit1", pButton2);  
  pButton2->signal_clicked().connect( sigc::ptr_fun(on_button_clicked2) );
	
//game screen
  builder->get_widget("gamescreen", pWindow2);
  pWindow2->set_size_request(625,475);

  builder->get_widget("image2",pImage);
  
  
builder->get_widget("FnameTB", pTextbox3);

builder->get_widget("LnameTB", pTextbox4);

builder->get_widget("guess", pButton3);  
  pButton3->signal_clicked().connect( sigc::ptr_fun(on_button_clicked3) );
//fail screen
  builder->get_widget("Fail_screen", pWindow3);
  pWindow3->set_size_request(625,475);
  builder->get_widget("Score", pLabel);
  builder->get_widget("Hscore", pLabel2);
  builder->get_widget("cont", pButton4);  
  pButton4->signal_clicked().connect( sigc::ptr_fun(on_button_clicked2) );

  builder->get_widget("quit", pButton5);  
  pButton5->signal_clicked().connect( sigc::ptr_fun(on_button_clicked2) );

//cont
 builder->get_widget("cont_screen", pWindow4);
  pWindow4->set_size_request(625,475);
  builder->get_widget("Cont_button",pButton6);
  pButton6->signal_clicked().connect( sigc::ptr_fun(on_button_clicked4) );

//start

pWindow->show();	
kit.run();
  //return app->run(*pOffwin);

}
void convert(){

string str = "wget -O temp.jpg -U Mozilla '";
str += get_ran_per();
str += "' --header Cookie: 'allow-download=1'";
const char * url = str.c_str();
system(url);

}

string get_ran_per(){//this func will pick a random person from vector
//int total = vector.size();
int total = 10;//for testing
srand(time(NULL));
int pick = rand() % total;
cout<<"pick: "<<pick<<"\ttotal: "<<total<<endl;
pick = rand() % total;

//url = vector[pick];
//return url;
return "https://scontent.xx.fbcdn.net/v/t1.0-1/c1.35.352.281/s160x160/10646779_727746920631662_3672973593794565525_n.jpg?oh=681e1e4275c72b44bce20758694a7b5c&oe=5A8DB78F";//url image from api

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

//run the fb login driver

convert();
curr_win_poss(); 
pImage ->set("temp.jpg");

pWindow2->show();
pWindow->hide();
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
if(pTextbox3->get_text() == "Fernando" && pTextbox4->get_text() == "Mendoza"){ //names of random picked per
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

void on_button_clicked4(){
curr_win_poss();
pWindow4->hide();
pWindow2->show();
}

