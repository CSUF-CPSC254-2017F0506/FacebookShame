#ifndef player_h
#define player_h

#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
#include <string>
#include <stdlib.h>



class Player{
public:
    Player();
    Player(std::string pname, size_t score);
    
    void createPlayerInfo();
    void insertInfo();
    void retrieveInfo();

    void setName(std::string pn);
    std::string getName()const;
    
    void setScore(size_t s);
    size_t getScore() const;
    
    std::string getHSName() const;
    size_t getHighScore() const;
    
    friend int callback(void *data, int argc, char **argv, char **azColName);

private:
  
    std::string player_name_;
    size_t score_;
    std::string hs_name_;
    size_t high_score_;
    
};

#endif
