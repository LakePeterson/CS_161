/*****************************************************
 ** Author: Lake Peterson
 ** Date: 10/21/2018
 ** Description: Connect Four Game
 ** Input:
 ** Output:
 ******************************************************/

#include <iostream>
#include <ctime>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>

using namespace std;

int valid(string);

void intro();

void displaySlot(int);

void printBoard(int**, int, int);

bool playerOneDrop(int**, int, int, bool&);

bool playerTwoDrop(int**, int, int, bool&);

bool botDropToken(int**, int, int, bool&);

bool checkHorizontal(int**, int, int, bool&, int, int);

bool checkVertical(int**, int, int, bool&, int, int);

bool checkDiagonalL(int**, int, int, bool&, int, int);

bool checkDiagonalR(int**, int, int, bool&, int, int);

int main(int argc, const char * argv[])
{
    int numPlayers = valid(argv[1]);
    int column = valid(argv[2]);
    int row = valid(argv[3]);
    
    srand(static_cast<unsigned int>(time(NULL)));
    bool checkWin = false;
    int** board = new int*[row];
    
    for(int i = 0; i < row; i++)
    {
        board[i] = new int[column];
        
        for(int j = 0; j < column; j++)
        {
            board[i][j] = 0;
        }
    }
    
    intro();
    
    if(numPlayers == 1)
    {
        printBoard(board, row, column);
        
        while(checkWin == false)
        {
            playerOneDrop(board, row, column, checkWin);
            
            botDropToken(board, row, column, checkWin);
        }
        
    }
    else if(numPlayers == 2)
    {
        printBoard(board, row, column);
        
        while(checkWin == false)
        {
            playerOneDrop(board, row, column, checkWin);
            
            playerTwoDrop(board, row, column, checkWin);
        }
    }
    else
    {
        cout << "Error: You have entered an invalid command line argument!" << endl;
    }
    
    cout << endl;
    
    for(int i = 0; i < row; i++)
    {
        delete [] board[i];
    }
    delete [] board;
    
    return 0;
}

/*********************************************************************
 ** Function: valid
 ** Description: takes in a string and outputs an integer
 ** Parameters: int
 ** Pre-Conditions: Takes in a user input of any type
 ** Post-Conditions: Outputs an integer
 ** ***********************************************************/

int valid(string str)
{
    int number;
    int sum = 0;
    
    for(int i = 0; i < str.length(); i++)
    {
        number = str[i];
        number -= 48;
        
        if(number < 0 || number > 9)
        {
            return INT_MAX;
        }
        sum += number * pow(10, str.length() - 1 - i);
    }
    return sum;
}

 /********************************************************************
 * ** Function: intro
 * ** Description: Prints out the instruction of the game for the user.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in predetermined text
 * ** Post-Conditions: Outputs text
 * ******************************************************************/

void intro()
{
    cout << endl;
    
    cout << "Welcome to the game of connect four, in order to start playing you must first decide who is going play first." << endl;
    
    cout << endl;
    
    cout << "• On your turn, drop one of your discs into ANY slot in the top of the grid." << endl;
    cout << "• Take turns until one player gets 4 of their color discs in a row – horizontally, vertically or diagonally." << endl;
    cout << "• If you’re the first to 4-in-a-row, you win!" << endl;
    
    cout << endl;
}

 /********************************************************************
 * ** Function: displaySlot
 * ** Description: Prints out the the slots to drop tokens for game board
 * ** Parameters: void
 * ** Pre-Conditions: Takes in an integer
 * ** Post-Conditions: Displays number of total columns
 * ******************************************************************/

void displaySlot(int column)
{
    int index = 0;
    
    cout << "  ";
    
    for(int i = 0; i < column; i++)
    {
        cout << index++ + 1 << " ";
    }
}

 /********************************************************************
 * ** Function: gameBoard
 * ** Description: Prints out the game board for the user.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in integers
 * ** Post-Conditions: Displays the game board
 * ******************************************************************/

void printBoard(int** board, int row, int column)
{
    displaySlot(column);
    
    cout << endl;
    
    for(int i = 0; i < row; i++)
    {
        cout << "| ";
        for(int j = 0; j < column; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

 /********************************************************************
 * ** Function: playerOneDrop
 * ** Description: Asks and places users game piece in selected column.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in 2-D array and two integers.
 * ** Post-Conditions: None
 * ******************************************************************/

bool playerOneDrop(int** board, int row, int column, bool &checkWin)
{
    int choice = 0;
    int count = 0;
    
    cout << endl;
    
    cout << "What column would you like to place your token player 1: ";
    do
    {
        cin >> choice;
        
        if(choice < 1 || choice > row)
        {
            cout << endl;
            cout << "Please enter a valid input: ";
        }
    }while(choice < 1 || choice > row);
    
    choice -= 1;
    cout << endl;
    
    if(choice >= 0 || choice < column)
    {
       if(board[0][choice] == 0)
       {
            while(count < row && board[count][choice] == 0)
            {
                count++;
            }
            board[count - 1][choice] = 1;
       }
    }
    printBoard(board, row, column);
    if((checkHorizontal(board, row, column, checkWin, count - 1, choice) == true || checkVertical(board, row, column, checkWin, count - 1, choice) == true) || checkDiagonalL(board, row, column, checkWin, count - 1, choice)  == true || checkDiagonalR(board, row, column, checkWin, count - 1, choice) == true)
    {
        cout << "Player 1 has won the game!" << endl;
        
        return checkWin;
    }
    return false;
}

/********************************************************************
 * ** Function: playerTwoDrop
 * ** Description: Asks and places users game piece in selected column.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in 2-D array and two integers.
 * ** Post-Conditions: None
 * ******************************************************************/

bool playerTwoDrop(int** board, int row, int column, bool &checkWin)
{
    int choice = 0;
    int count = 0;
    
    cout << endl;
    
    cout << "What column would you like to place your token player 2: ";
    cin >> choice;
    
    choice -= 1;
    cout << endl;
    
    if(choice >= 0 || choice < column)
    {
        if(board[0][choice] == 0)
        {
            int count = 0;
            
            while(count < row && board[count][choice] == 0)
            {
                count++;
            }
            board[count - 1][choice] = 2;
        }
    }
    printBoard(board, row, column);
    /*if((checkHorizontal(board, row, column, checkWin, count - 1, choice) == true || checkVertical(board, row, column, checkWin, count - 1, choice) == true) || checkDiagonalL(board, row, column, checkWin, count - 1, choice)  == true || checkDiagonalR(board, row, column, checkWin, count - 1, choice) == true)
    {
        cout << "Player 2 has won the game!" << endl;
        
        return checkWin;
    }*/
    return false;
}

 /********************************************************************
 * ** Function: botDropToken
 * ** Description: Computer randonly selects a column to place game token.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in 2-D array and two integers.
 * ** Post-Conditions: None
 * ******************************************************************/

bool botDropToken(int** board, int row, int column, bool &checkWin)
{
    int choice = 0;
    int count = 0;
    
    choice = rand() % column;
    
    cout << endl;
    
    cout << "The computer has chosen to place its token in column " << choice + 1 << endl;
    
    cout << endl;
    
    if(choice > 0 || choice < column)
    {
        if(board[0][choice] == 0)
        {
            int count = 0;
            
            while(count < row && board[count][choice] == 0)
            {
                count++;
            }
            board[count - 1][choice] = 2;
        }
    }
    printBoard(board, row, column);
    /*if((checkHorizontal(board, row, column, checkWin, count - 1, choice) == true || checkVertical(board, row, column, checkWin, count - 1, choice) == true) || checkDiagonalL(board, row, column, checkWin, count - 1, choice)  == true || checkDiagonalR(board, row, column, checkWin, count - 1, choice) == true)
     {
     cout << "Player 2 has won the game!" << endl;
     
     return checkWin;
     }*/
    return false;
}

 /********************************************************************
 * ** Function: checkHorizontal
 * ** Description: Checking for 4 horizontal token in a row.
 * ** Parameters: bool
 * ** Pre-Conditions: Takes in 2-D array, two integers, and bool.
 * ** Post-Conditions: Returns a bool to check for winner.
 * ******************************************************************/

bool checkHorizontal(int** board, int row, int column, bool& checkWin, int currentRow, int currentColumn)
{
    int check = board[currentRow][currentColumn];
    int count = 0;
    
    for(int i = -3; i < 4; i++)
    {
        if(currentColumn + i >= 0 && currentColumn + i < column)
        {
            if(board[currentRow][currentColumn + i] == check)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count == 4)
            {
                checkWin = true;
                return checkWin;
            }
        }
    }
    return false;
}

 /********************************************************************
 * ** Function: checkVertical
 * ** Description: Checking for 4 vertical tokens in a row.
 * ** Parameters: bool
 * ** Pre-Conditions: Takes in 2-D array, two integers, and bool.
 * ** Post-Conditions: Returns a bool to check for winner.
 * ******************************************************************/

bool checkVertical(int** board, int row, int column, bool& checkWin, int currentRow, int currentColumn)
{
    int check = board[currentRow][currentColumn];
    int count = 0;
    
    for(int i = -3; i < 4; i++)
    {
        if(currentRow + i >= 0 && currentRow + i < row)
        {
            if(board[currentRow + i][currentColumn] == check)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count == 4)
            {
                checkWin = true;
                return checkWin;
            }
        }
    }
    return false;
}

 /********************************************************************
 * ** Function: checkHorizontal ----- Right
 * ** Description: Checking for 4 vertical tokens in a row.
 * ** Parameters: bool
 * ** Pre-Conditions: Takes in 2-D array, two integers, and bool.
 * ** Post-Conditions: Returns a bool to check for winner.
 * ******************************************************************/

bool checkDiagonalR(int** board, int row, int column, bool& checkWin, int currentRow, int currentColumn)
{
    int check = board[currentRow][currentColumn];
    int count = 0;
    
    for(int i = -3; i < 4; i++)
    {
        if(currentRow + i >= 0 && currentRow + i < row && currentColumn + i >= 0 && currentColumn + i < column)
        {
            if(board[currentRow + i][currentColumn + i] == check)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count == 4)
            {
                checkWin = true;
                return checkWin;
            }
        }
    }
    return false;
}

/********************************************************************
 * ** Function: checkHorizontal ----- Left
 * ** Description: Checking for 4 vertical tokens in a row.
 * ** Parameters: bool
 * ** Pre-Conditions: Takes in 2-D array, two integers, and bool.
 * ** Post-Conditions: Returns a bool to check for winner.
 * ******************************************************************/

bool checkDiagonalL(int** board, int row, int column, bool& checkWin, int currentRow, int currentColumn)
{
    int check = board[currentRow][currentColumn];
    int count = 0;
    
    for(int i = -3; i < 4; i++)
    {
        if(currentRow - i >= 0 && currentRow - i < row && currentColumn + i >= 0 && currentColumn + i < column)
        {
            if(board[currentRow - i][currentColumn + i] == check)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count == 4)
            {
                checkWin = true;
                return checkWin;
            }
        }
    }
    return false;
}
