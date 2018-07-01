#include "Game.h"
#include<iostream>
#include<cstdlib>
#include<windows.h>


using namespace std;

//! Default Constructor

Game::Game()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<sizeof(cell)/sizeof(cell[0]); j++)
        {
            cell[i][j]= "NULL";
        }
    }

    //! Calling Method Gamerun for implementing Class Game & Running the game

    Gamerun();

}

//! Implementation of Method Gamerun for implementing Class Game & Running the game

void Game::Gamerun()
{

    int x;

    while(true)
    {
        system("cls");
        cout << "Player ";
        cout << turn;
        cout << " Turn: Enter from 1 to 9!" << endl;

        if(isFull() == false)
        {
            if(winCase() == true)
            {
                cout <<" GAME OVER!! \n";
                cout << "The Winner Player " << turnRev() << endl;
                display();
                return;
            }
            cin >> x;
            set_loc(x);
            setCell(ret_loc());
            display();
            Sleep(3000);
        }
        else
        {
            cout <<"Tie" << endl;
            display();
            return;
        }

    }



}

// Case Block to insert X or O on which location

void Game::setCell(int x)
{

    switch(x)
    {

    case 1:
        if(cell[0][0] == "NULL")
        {
            cell[0][0] = xTurn();
            break;
        }

        else
        {
            cout <<"Cell is N/A " << endl;

            break;
        }
    case 2:
        if(cell[0][1]== "NULL")
        {
            cell[0][1] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;

    case 3:
        if(cell[0][2]== "NULL")
        {
            cell[0][2] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;

    case 4:
        if(cell[1][0]== "NULL")
        {
            cell[1][0] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;

    case 5:
        if(cell[1][1]== "NULL")
        {
            cell[1][1] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;
    case 6:
        if(cell[1][2]== "NULL")
        {
            cell[1][2] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;

    case 7:
        if(cell[2][0]== "NULL")
        {
            cell[2][0] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;
    case 8:
        if(cell[2][1]== "NULL")
        {
            cell[2][1] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;
    case 9:
        if(cell[2][2]== "NULL")
        {
            cell[2][2] = xTurn();
            break;
        }
        else
            cout <<"Cell is N/A" << endl;
        break;


    default:
        cout <<"Out of bounds ";
        break;

    }
}

// Set value inside X to private variable loc

void Game::set_loc(int loc)
{

    this-> loc = loc;


}

// Return loc
int Game::ret_loc()
{

    return loc;


}
/////

/*void Game::setTurn(){

    if(turn == "X"){
            cout << "This is == X/" << turn << endl;
        turn = "O";

    }
    else if(turn == "O"){
             cout << "This is == O/" << turn << endl;
        turn = "X";

    }

} */

// Determine which Players has the turn
string Game::xTurn()
{

    if(turn == "X")
    {
        turn = "O";
        return "X";
    }
    else if(turn == "O")
    {
        turn = "X";
        return "O";
    }

}

// Check if the board is Full
bool Game::isFull()
{
    int flag= 1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(cell[i][j] == "NULL")
            {
                flag =0;
            }

        }
    }
    if(flag == 0)
    {
        return false;
    }
    else
        return true;

}

// winning Conditions
bool Game::winCase()
{

    for (int row = 0; row < 3; row++)
    {
        if ((cell[row][0] == "X" && cell[row][1] == "X" && cell[row][2] == "X") || (cell[row][0] == "O" && cell[row][1] == "O" && cell[row][2] == "O"))
        {
            return true;
        }
        else if ((cell[0][row] == "X" && cell[1][row] == "X" && cell[2][row] == "X") || (cell[0][row] == "O" && cell[1][row] == "O" && cell[2][row] == "O"))
        {
            return true;
        }
    }
    if ((cell[0][0] == "X" && cell[1][1] == "X" && cell[2][2] == "X") || (cell[0][0] == "O" && cell[1][1] == "O" && cell[2][2] == "O"))
    {
        return true;
    }
    else if ((cell[0][2] == "X" && cell[1][1] == "X" && cell[2][0] == "X") || (cell[0][2] == "O" && cell[1][1] == "O" && cell[2][0] == "O"))
    {
        return true;
    }
    return false;
}

// Return which Player won the game
string Game::turnRev()
{
    if(turn == "X")
        return "O";
    else
        return "X";

}

// Display the final board
void Game::display()
{

    int k = 1;
    for(int i=0; i<3; i++)
    {
        cout<<"+-------------------------------+"<<endl;
        for(int j=0; j<3; j++)
        {

            cout << "| ";
            if(cell[i][j]=="NULL")
                cout<<k;
            else
                cout<<cell[i][j];
            cout <<"\t";
            k++;
        }
        cout <<"\t|"<< endl;
    }
    cout<<"+-------------------------------+"<<endl;
}
