#include <iostream>
using namespace std;

// Global 3x3 board
char board[3][3];

// Function to initialize the board
void initializeBoard()
{
    char value = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value++;
        }
    }
}

// Function to display the board
void displayBoard()
{
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     \n\n";
}

// Function to check win
bool checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main()
{
    char currentPlayer;
    int choice;
    bool gameOver;
    char playAgain;

    do
    {
        initializeBoard();
        currentPlayer = 'X';
        gameOver = false;

        while (!gameOver)
        {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Validate move
            if (choice >= 1 && choice <= 9 &&
                board[row][col] != 'X' && board[row][col] != 'O')
            {
                board[row][col] = currentPlayer;

                // Check win
                if (checkWin())
                {
                    displayBoard();
                    cout << "?? Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                }
                // Check draw
                else if (checkDraw())
                {
                    displayBoard();
                    cout << "?? Game is a draw!\n";
                    gameOver = true;
                }
                else
                {
                    // Switch player
                    if (currentPlayer == 'X')
                        currentPlayer = 'O';
                    else
                        currentPlayer = 'X';
                }
            }
            else
            {
                cout << "? Invalid move! Try again.\n";
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing Tic-Tac-Toe! ??\n";
    return 0;
}
 