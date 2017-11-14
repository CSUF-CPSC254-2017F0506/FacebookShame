#include <gtkmm.h>
#include <iostream>
#include <string>
using namespace std;
//vars
std::string name = "";
std::string Fname;
std::string Lname;
std::string temparry[] = {"1","2","3","4","5","6","7","8"};

int score = 0;


void curr_win_poss();
void set_image();
void get_ran_per(std::string arry[]);
void convert();

//login 


Gtk::Entry* pTextbox2 = nullptr;
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
//cont
Gtk::Window* pWindow4 = nullptr;
Gtk::Button* pButton6 = nullptr;
//funcs
void on_button_clicked();//login
void on_button_clicked2();//quit
void on_button_clicked3();//submit guess
void on_button_clicked4();//on continue
//vars


int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
  //auto app =  Gtk::Application::create(argc, argv);

  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("hello.glade");

  
//login
  builder->get_widget("entry2", pTextbox2);
  pTextbox2->set_text("password");  

  
  builder->get_widget("hello_window", pWindow);
  pWindow->set_size_request(625,475);
  pWindow->set_resizable(false);

 
  builder->get_widget("entry1", pTextbox);
  pTextbox->set_text("user_name");

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
std::cout << "test out" << std::flush;

}
void convert(){
get_ran_per(temparry);
string str = "wget -O temp.jpg -U Mozilla 'https://scontent.xx.fbcdn.net/v/t1.0-1/c6.0.159.127/993016_10203299800200766_1300003533_n.jpg?oh=03e6e3b3980f81bd6eeee7f48bcdafee&oe=5A66CFBF' --header Cookie: 'allow-download=1'";
const char * url = str.c_str();
system(url);

}
void set_image(){

}
void get_ran_per(std::string arry[]){
int x = 4;
std::cout <<"length :"<<sizeof(arry[0])<< std::flush;
//int pick = rand() % x;
//std::cout << pick << std::flush;

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


void on_button_clicked(){

//std::cout << pTextbox->get_text() << std::flush;
convert();
curr_win_poss(); 
pImage ->set("temp.jpg");

pWindow2->show();
pWindow->hide();
  
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
if(pTextbox3->get_text() == "Fernando" && pTextbox4->get_text() == "Mendoza"){ 
score++;
std::cout << score << std::flush;
pWindow4->show(); 
}
else{
name = pLabel->get_text(); 
  name += std::to_string(score);
  pLabel->set_text(name);
std::cout << name << std::flush;
pWindow3->show(); 
}
}
void on_button_clicked4(){
curr_win_poss();
pWindow4->hide();
pWindow2->show();
}

