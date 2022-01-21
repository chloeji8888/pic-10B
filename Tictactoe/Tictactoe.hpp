#ifndef Tictactoe_hpp
#define Tictactoe_hpp

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>

/**
 @class Player stores each players' information and to update
 their information and to retrieve theri information
 */
class Player{
private:
    
    std::string name;
    int score = 0;
    
public:
    
    /**
     This constructer is used to get name and score and increment scores for the player
     @param _name is the players's name
     @param _score is the player's score
     */
    Player(const std::string& _name, const int& _score);
    
    /**
     This function get the score of the player
     @return the socre of the player
     */
    int get_score()const;
    
    /**
     This function get the name of the player
     @return the string of name of the player
     */
    std::string get_name()const;
    
    /**
     This function increments the score for each player
     */
    void add_score();
    
};



#endif
