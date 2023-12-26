/*
________________________________________________________________________
The following program is a game called Boogle. It presents a board where
the user's objective is to find words formed on the board by contiguous
sequences of letters.
_________________________________________________________________________
The program displays a random board and allows the user to enter random
words.  The program will report if the word entered by the user is on the
board or not.  The program will stop when the user enters ****.
___________________________________________________________________________
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

const int boardSize = 5; // Setting the size of the Boggle board (5x5) 

// Checking if the cell is out of bounds
bool outOfBound(int row, int col)
{
    return (row < 0 || row >= boardSize || col < 0 || col >= boardSize);
}

// Function prints the Boggle board after finding the word
void printBoard(char board[][boardSize], bool used[][boardSize])
{
    cout << "\t\tThe following letters were used:" << endl
         << endl;
    for (int i = 0; i < boardSize; ++i)
    {
        cout << "  \t\t  ";
        for (int j = 0; j < boardSize; ++j)
        {
            if (used[i][j])
            {
                cout << board[i][j] << ' ';
            }
            else
            {
                cout << '#' << ' ';
            }
        }
        cout << endl;
    }
}

// Recursive function to find a word on the board 
bool search(char board[][boardSize], bool used[][boardSize], string word, int nextLetterIndex, int row, int col)
{
    // Base cases
    if (nextLetterIndex == word.length()) 
    {
        printBoard(board, used);
        cout << endl
             << "This board contains " << word << ".\n\n";
        return true;
    }

    if (outOfBound(row, col) || used[row][col] || (board[row][col]) != (word[nextLetterIndex])) 
    {
        return false;
    }

    // Saving the current state of 'used'
    bool prevUsed = used[row][col];
    used[row][col] = true;

    // Defining the possible moves (horizontal, vertical, and diagonal )
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Recursively searching each neighboring cell
    for (int dir = 0; dir < 8; ++dir)
    {
        int newRow = row + dr[dir];
        int newCol = col + dc[dir];
        if (search(board, used, word, nextLetterIndex + 1, newRow, newCol))
        {
            // Cell is part of the word if it returns true
            return true;
        }
    }

    // Restoring the state of 'used'
    used[row][col] = prevUsed;

    return false; // Failing condition
}

void clearscreen()
{
// Clearing the screen after every loop based on the system used
#ifdef _WIN32
    system("cls");
#elif defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    cout << "\033[2J\033[1;1H";
#endif
}

int main()
{
    char board[boardSize][boardSize];
    bool used[boardSize][boardSize] = {false}; // Initializing that none of the cells are used

    // Seeding the random number sequence using clock time 
    srand(time(0));

    // Creating the Boggle board
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            char letter = 'A' + rand() % 26; // Generating a random letter from 'A' to 'Z' 
            board[i][j] = letter;
        }
    }
    string word;

    // Main game loop
    while (true)
    {
        clearscreen();
        // Printing the Boggle board
        cout << "\t\tYour Boggle Board:" << endl
             << endl;
        for (int i = 0; i < boardSize; ++i)
        {
            cout << "  \t\t  ";
            for (int j = 0; j < boardSize; ++j)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        cout << "Please enter a word to see if it's on board. Enter **** to stop." << endl;
        cout << "-->";
        cin >> word;
        if (word == "****")
        {
            break;
        }

        // word to uppercase
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = toupper(word[i]);
        }

        bool found = false;
        // Searching for the word from each cell on the board
        for (int i = 0; i < boardSize; ++i)
        {
            for (int j = 0; j < boardSize; ++j)
            {
                if (search(board, used, word, 0, i, j))
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }

        if (!found)
        {
            cout << endl
                 << word << " is not on this board."
                 << "\n\n";
        }

        // Resetting the 'used' array for the next word search
        for (int i = 0; i < boardSize; ++i)
        {
            for (int j = 0; j < boardSize; ++j)
            {
                used[i][j] = false;
            }
        }
        cout << "Press <Enter> key to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
