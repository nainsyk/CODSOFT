#include <iostream>
#include <vector>

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal from top-left to bottom-right
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal from top-right to bottom-left
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell != 'X' && cell != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    bool playAgain = true;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
     while (playAgain) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;


    while (!gameWon && !gameDraw) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            gameWon = true;
        } else if (checkDraw(board)) {
            gameDraw = true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    displayBoard(board);

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
     char playAgainChoice;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgainChoice;

        playAgain = (playAgainChoice == 'y' || playAgainChoice == 'Y');
    }

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;

    return 0;
}
