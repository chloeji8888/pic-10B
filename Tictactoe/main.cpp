#include <stdio.h>
#include<iostream>
#include<string>
#include"Tictactoe.hpp"

using namespace std;

int main(){
    
    //asking for user input of player names and rounds number
    cout << "This is a Tic Tac Toe game!";
    cout << "\nPlease enter the name of player 1:";
    string name1;
    getline(cin, name1);
    cout << "Thanks. Please enter the name of player 2: ";
    string name2;
    getline(cin, name2);
    cout << "How many rounds would you like to play?";
    int rounds;
    cin >> rounds;
    cout << "Let the game begin!" << "\n" ;
    
    //The players scores are now 0
    int score1 = 0;
    int score2 = 0;
    
    //construct objects for the players
    Player player_1 (name1, score1);
    Player player_2 (name2, score2);
    
    int alternate = 2;
    
    for(int round = 0; round < rounds; ++round){
        //for "rounds" many rounds, we do the following...
        
        //both player are not win at the begining
        bool player1_win = false;
        bool player2_win = false;
        
        //vector for the horizontal broad
        vector<string> board(3);
        board[0]= "1 | | ";
        board[1]= "2 | | ";
        board[2]= "3 | | ";
        
        //print the initial broad
        cout << " 1 2 3" << "\n";
        cout << board[0] << "\n" << " -----" << "\n" ;
        cout << board[1] << "\n" << " -----" << "\n" ;
        cout << board[2] << "\n";
        
        int i = 0;
        
        for( i = 0; i < 9; ++i){
            //since there are 9 blanck in total, we loop through them
            int row = 0;
            int col = 0;
            
            string player = " ";
            string point = " ";
            
            if ((i + alternate) % 2 == 0){//first player's roll
                
                player = player_1.get_name();//get first player's name
                
                point="x";//fill the corresponding blank with 'x'
            }
            
            if ((i + alternate) % 2 == 1){//second player's roll
                
                player = player_2.get_name();//get the second player's name
                
                point="o";//fill the corresponding blank with 'o'
            }
            
            //ask for the spot
            cout << "It is " << player << "'s turn.\n";
            cout << "Where would you like to play? Enter your row position and column position: row col:";
            cin >> row >> col;
            
            //replace the blank with marks
            row=row-1;
            col=col*2-1;
            board[row].replace(col,1,point);
            cout << " 1 2 3" << "\n";
            cout << board[0] << "\n" << " -----" << "\n" ;
            cout << board[1] << "\n" << " -----" << "\n" ;
            cout << board[2] << "\n";
            
            //check which player won the current round
            int j = 0;
            
            //check the horizontal
            if (board[j] == "1x|x|x" || board[j + 1] == "2x|x|x"||board[j + 2] == "3x|x|x"){
                player1_win = true;
            }
            if(board[j] == "1o|o|o" || board[j + 1] == "2o|o|o"||board[j + 2] == "3o|o|o"){
                player2_win = true;
            }
            
            //check the vertical
            for (j = 1; j < 6; j+=2){
                
                if (board[0].substr(j,1)=="x" && board[1].substr(j,1)=="x" && board[2].substr(j,1)=="x"){
                    player1_win = true;
                }
                
                if (board[0].substr(j,1)=="o" && board[1].substr(j,1)=="o" && board[2].substr(j,1)=="o"){
                    player2_win = true;
                }
            }
            
            //check the diagnol
            if (board[0].substr(1,1)=="x" && board[1].substr(3,1)=="x" && board[2].substr(5,1)=="x"){
                player1_win = true;
            }
            
            if (board[0].substr(1,1)=="o" && board[1].substr(3,1)=="o" && board[2].substr(5,1)=="o"){
                player2_win = true;
            }
            
            if (board[0].substr(5,1)=="x" && board[1].substr(3,1)=="x" && board[2].substr(1,1)=="x"){
                player1_win = true;
            }
            
            if (board[0].substr(5,1)=="o" && board[1].substr(3,1)=="o" && board[2].substr(1,1)=="o"){
                player2_win = true;
            }
            
            
            
            if(player1_win){
                /*
                 if the first player won the current round,increment the score of the first player
                 stop the current loop by seting i to 9
                 make the second player the first turn by seting alternate to 1
                 */
                player_1.add_score();
                i = 9;
                cout << player_1.get_name();
                alternate = 1;
            }else if(player2_win){
                /*
                 if the second player won the current round,increment the score of the second player
                 stop the current loop by seting i to 9
                 make the first player the first turn by seting alternate to 2
                 */
                player_2.add_score();
                i = 9;
                cout << player_2.get_name();
                alternate = 2;
            }
            
        }
        
        if (!player1_win && !player2_win){
            // if neither players won the game, print "No one won this game"
            cout << "No one";
        }
        //print who won in this current round and a summary of current score
        cout << " won the round!";
        cout << "\nPresently, "<< name1 << " has " << player_1.get_score() << " points and ";
        cout << name2 << " has " << player_2.get_score() << " points. \n";
        
    }
    
    // get the score of the first player and the seond player
    score1 = player_1.get_score();
    score2 = player_2.get_score();
    
    //compare the two scores and get a score summary at the end of rounds.
    if(score1 == score2){
        cout << "It is a draw!\n";
    }else if(score1 > score2){
        cout << player_1.get_name() << " won the game with a score of " << score1 << '\n';
    }else if (score1 < score2){
        cout << player_2.get_name() << " won the game with a score of " << score2 << '\n';
    }
    
    return 0;
}
