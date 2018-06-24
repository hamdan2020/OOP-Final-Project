#ifndef GAME_H
#define GAME_H
#include<iostream>
using namespace std;
// GAME CLASS
class Game

{
private:
    string cell[3][3];
    int loc;

    public:
        Game();
        void set_loc(int loc);
        int ret_loc();
        string turn = "X";
        void display();
        void setTurn();
        string xTurn();
        string turnRev();
        void setCell(int y);
        void Gamerun();
        bool isFull();
        bool winCase();

};

#endif // GAME_H
