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
    Player(size_t pid, std::string pname, size_t score);
    
    void insertInfo();
    void retrieveInfo();

    void setId(size_t id);
    size_t getId() const;

    void setName(std::string pn);
    std::string getName()const;
    
    void setScore(size_t s);
    size_t getScore() const;
    
    void setHighScore(size_t hs);
    size_t getHighScore() const;
    
    friend int callback(void *data, int argc, char **argv, char **azColName);

private:
    size_t player_id_;
    std::string player_name_;
    size_t score_;
    size_t high_score_;
    
};

#endif
