// TripleA Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.

//needs random turn function 
//replay(w win counter)/exit game 
//user input check

#include <iostream>
#include <stdlib.h>
using namespace std;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice, row, column, playerX_wins=0, playerO_wins=0; //for keeping track of i/o
char player_turnchar = 'X'; //keeping track of who's turn it is in the game. (im pretty sure we technically could make this into a bool, but im not sure exactly what id need to change from here to make that work)
bool draw = false; //choice for if game is draw
int randomizer_value = rand() % 2 + 1;


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

//Function to get the player input and update the board

void player_turn()
{
    if (player_turnchar == 'X')
        cout << "Player 1 [X] turn : ";
    else if (player_turnchar == 'O')
        cout << "Player 2 [O] turn : ";
    cin >> choice; //geting the placement input from user
    if (choice <= 9 && choice >= 1)
    {
        switch (choice) { //switch case to get which row and column will be update (9 places for a move 9 cases)
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move";
        }
        if (player_turnchar == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
            //making sure to check that there is an open space and it is the correct players turn
            board[row][column] = 'X'; // putting the correct player's move into the spot selected on the board
            player_turnchar = 'O'; //switching the move to the other player
        }
        else if (player_turnchar == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
            board[row][column] = 'O'; //repeating the process from above
            player_turnchar = 'X';
        }
        else {
            cout << "Box already filled! Please choose another!!";
            player_turn();//iand f input position already filled throws error message and restarts turn
        }
        display_ui(); //displaying board at end of turn for next turn
    }

    else
    {
        cout << "Please enter a number between 1 and 9" << endl;
        player_turn();
    }
}

void resetGame()
{
    // Reset the board and other game-related variables
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + i * 3 + j;
        }
    }
    draw = false;
    if (randomizer_value == 1)
    {
        player_turnchar = 'X';
    }
    else if(randomizer_value == 1)
    {
        player_turnchar = 'O';
    }
}

void win_counter(int playerOneScore, int playerTwoScore)
{
    cout << "\nPlayer O:" + playerOneScore << " Player X: " << playerTwoScore << endl;
}

bool gameover() 
{
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false; //this is a very simple way of checking for a win through col and row

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false; //this checks for a win in both diagonals

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;//this checks to see if the game is still being played or has stopped by win 

    draw = true;//Checking to see if game already draw
    return false;
}

bool continueGame()
{
    cout << "\nDo you want to play again? (Y/N): ";
    char playAgain;
    cin >> playAgain;
    return (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
    cout << "TIC TAC TOE GAME FOR TWO PLAYERS\n";
    cout << "Choose the number that corresponds to the position you want\n";
    do 
    {
        display_ui();
        resetGame();
        while (gameover()) { //game running through
            player_turn();
            gameover();
        }
        if (player_turnchar == 'X' && draw == false) {
            cout << "CONGRATULATIONS!! PLAYER O HAS WON THE GAME";
            resetGame();
            playerO_wins++;

        }
        else if (player_turnchar == 'O' && draw == false) {
            cout << "CONGRATULATIONS!! PLAYER X HAS WON THE GAME";
            resetGame();
            playerX_wins++;
        }
        else
            cout << "GAME IS A DRAW!!!";

        win_counter(playerO_wins, playerX_wins);

        if (!continueGame()) {
            cout << "Thank you for playing! Goodbye." << endl;
            break;  // Exit the loop and end the program
        }
    } while (true);
        return 0;
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
