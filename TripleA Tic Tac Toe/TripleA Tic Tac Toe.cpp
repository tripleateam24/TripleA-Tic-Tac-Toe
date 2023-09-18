// TripleA Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdlib.h>
using namespace std;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice, row, column; //for keeping track of i/o
char player_turnchar = 'X'; //keeping track of who's turn it is in the game. (im pretty sure we technically could make this into a bool, but im not sure exactly what id need to change from here to make that work)
bool draw = false; //choice for if game is draw


void display_ui() {

    //this will start by displaying each spot on the board with a Number for the player to input as their move
    // I think this is a cleanest and easiest way to make the 3x3 look continually readable
    cout << "\nPlayer 1[X]    Player 2[O]\n";
    cout << "     |     |    \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |    \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |    \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "     |     |    \n";
}

int main()
{
    std::cout << "Hello World!\n";
}


    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
