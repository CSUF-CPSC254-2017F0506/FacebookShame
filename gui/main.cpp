#include <gtkmm.h>
#include <iostream>
#include <string>
using namespace std;
void curr_win_poss();
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
Gtk::Label* pLabel = nullptr;
//cont
Gtk::Window* pWindow4 = nullptr;
void on_button_clicked();//login
void on_button_clicked2();//quit
void on_button_clicked3();//submit guess
//vars
std::string name = "";
int score = 0;
int main(int argc, char *argv[])
{
  auto app =  Gtk::Application::create(argc, argv);
cout<<"hello"<<endl;
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
  pImage ->set_size_request(100,100);
  
builder->get_widget("FnameTB", pTextbox3);

builder->get_widget("LnameTB", pTextbox4);

builder->get_widget("guess", pButton);  
  pButton->signal_clicked().connect( sigc::ptr_fun(on_button_clicked3) );
//fail screen
 builder->get_widget("Fail_screen", pWindow3);
  pWindow3->set_size_request(625,475);
 builder->get_widget("Score", pLabel);
  

//cont
 builder->get_widget("cont_screen", pWindow4);
  pWindow4->set_size_request(625,475);

  return app->run(*pWindow);

}
void curr_win_poss(){//save window position
int x,y;
if(pWindow){
pWindow->get_position(x,y);
pWindow2->move(x,y);
}
}

void on_button_clicked(){

//std::cout << pTextbox->get_text() << std::flush;
curr_win_poss(); 
pWindow2->show();
 
//pWindow->hide();
  
}
void on_button_clicked2(){//quit
pWindow->hide();
delete pWindow;
}
void on_button_clicked3(){//guess
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
