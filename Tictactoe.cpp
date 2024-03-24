#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void display_board(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if the game is over
bool game_over(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return true;
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to check if the move is valid
bool is_valid_move(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty board
    int row, col;
    char player = 'X';

    while (!game_over(board)) {
        display_board(board);

        // Get input from the current player
        cout << "Player " << player << ", enter row (1-3) and column (1-3) separated by space: ";
        cin >> row >> col;
        row--; // Convert to 0-indexing
        col--;

        // Check if the move is valid
        if (is_valid_move(board, row, col)) {
            board[row][col] = player;
            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    display_board(board);

    // Check if there's a winner or if it's a tie
    if (game_over(board)) {
        if (player == 'X') {
            cout << "Player O wins!" << endl;
        } else {
            cout << "Player X wins!" << endl;
        }
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
