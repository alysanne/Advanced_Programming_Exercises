#include <iostream>
using namespace std;

const char PLAYER_1 = 'O';
const char PLAYER_2 = 'X';
char board[3][3];

// Exercise 4
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

// Exercise 1
void Initialise() {
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void Display() {
    cout << endl;
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            cout << board[i][j] << '\t';
        }
        cout << endl << endl;
    }
}

// Exercise 2
void SetValue(int row, int col, char symbol) {
    board[row][col] = symbol;
}

bool IsFree(int row, int col) {
    return board[row][col] == '-';
}

// Exercise 5
bool HasWon(char symbol) {
    int row = 0, col = 0;
    bool match = false;

    for (int m=0; m<8; m++) {
        for (int s=0; s<3; s++) {
            row = winningStates[m][s][0];
            col = winningStates[m][s][1];

            if (board[row][col] == symbol) {
                match = true;
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
    // Exercise 3
    srand(time(NULL));
    bool gameOver = false;
    int row = 0, col = 0;
    char player = PLAYER_1;
    int count = 0;

    Initialise();
    Display();

    while(!gameOver) {
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!IsFree(row, col));

        SetValue(row, col, player);
        player = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        count++;

        if (count == 9) {
            gameOver = true;
            Display();
        }
    }

    cout << HasWon('X') << endl;
    cout << HasWon('O') << endl;
}