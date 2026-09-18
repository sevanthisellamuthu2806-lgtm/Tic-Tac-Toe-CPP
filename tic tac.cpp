#include <iostream>
using namespace std;

char board[3][3];

// Display the game board
void displayBoard() {
    cout << "\n";
    cout << "    1   2   3\n";
    cout << "  -------------\n";

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " | ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }

        cout << "\n";
        cout << "  -------------\n";
    }
}

// Check whether a player has won
bool checkWin(char player) {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player) {
            return true;
        }
    }

    // Diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    return false;
}

// Check whether the board is full
bool checkDraw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Reset the board
void resetBoard() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {

    char playAgain;

    do {

        resetBoard();

        char currentPlayer = 'X';
        bool gameOver = false;

        cout << "\n================================\n";
        cout << "        TIC TAC TOE GAME\n";
        cout << "================================\n";

        cout << "\nPlayer 1 : X";
        cout << "\nPlayer 2 : O\n";

        while (!gameOver) {

            displayBoard();

            int row, column;

            cout << "\nPlayer " << currentPlayer;
            cout << ", enter row and column: ";
            cin >> row >> column;

            // Convert to array index
            row--;
            column--;

            // Check valid position
            if (row < 0 || row >= 3 ||
                column < 0 || column >= 3) {

                cout << "\nInvalid position! Try again.\n";
                continue;
            }

            // Check whether position is already occupied
            if (board[row][column] != ' ') {

                cout << "\nPosition already occupied! Try again.\n";
                continue;
            }

            // Place player's symbol
            board[row][column] = currentPlayer;

            // Check winner
            if (checkWin(currentPlayer)) {

                displayBoard();

                cout << "\nPlayer " << currentPlayer << " wins!\n";

                gameOver = true;
            }

            // Check draw
            else if (checkDraw()) {

                displayBoard();

                cout << "\nGame Draw!\n";

                gameOver = true;
            }

            // Change player
            else {

                if (currentPlayer == 'X')
                    currentPlayer = 'O';
                else
                    currentPlayer = 'X';
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing Tic Tac Toe!\n";

    return 0;
}