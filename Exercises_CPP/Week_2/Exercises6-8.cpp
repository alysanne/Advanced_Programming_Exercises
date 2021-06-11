#include <iostream>
using namespace std;

const char PLAYER_1 = 'O';
const char PLAYER_2 = 'X';

int winningStates[8][3][2] = {
    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}},
    {{0, 2}, {1, 1}, {2, 0}},
};

void Initialise(char board[][3]) {
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void Display(char board[][3]) {
    cout << endl;
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            cout << board[i][j] << '\t';
        }
        cout << endl << endl;
    }
}

// Exercise 7: Make unchangeable vars constants
void SetValue(const int row, const int col, const char symbol, char board[][3]) {
    board[row][col] = symbol;
}

bool IsFree(const int row, const int col, char board[][3]) {
    return board[row][col] == '-';
}

// Exercise 8: add functionality to save winning combo
bool HasWon(const char symbol, char board[][3], int winningCombo[][2]) {
    int row = 0, col = 0;
    bool match = false;

    for (int m=0; m<8; m++) {
        for (int s=0; s<3; s++) {
            row = winningStates[m][s][0];
            col = winningStates[m][s][1];

            if (board[row][col] == symbol) {
                match = true;
                winningCombo[s][0] = row;
                winningCombo[s][1] = col;
            } else {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }

    return false;
}

int main() {
    // Exercise 6: board inside main rather than global
    char board[3][3];

    srand(time(NULL));
    bool gameOver = false;
    int row = 0, col = 0;
    char player = PLAYER_1;
    int count = 0;

    Initialise(board);
    Display(board);

    while(!gameOver) {
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!IsFree(row, col, board));

        SetValue(row, col, player, board);
        player = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        count++;

        if (count == 9) {
            gameOver = true;
            Display(board);
        }

    }
    int xWinningCombo[3][2];
    bool xWon = HasWon('X', board, xWinningCombo);

    if (xWon) {
        cout << "X has won with coordinates: ";
        for (int i=0; i < 3; i++) {
            cout << "[" << xWinningCombo[i][0] << ", " << xWinningCombo[i][1]<< "] ";
        }
        cout << endl;
    } else {
        cout << "X has lost" << endl;
    }
    
    int oWinningCombo[3][2];
    bool oWon = HasWon('O', board, oWinningCombo);

    if (oWon) {
        cout << "O has won with coordinates: ";
        for (int i=0; i < 3; i++) {
            cout << "[" << oWinningCombo[i][0] << ", " << oWinningCombo[i][1]<< "] ";
        }
        cout << endl;
    } else {
        cout << "O has lost" << endl;
    }
}