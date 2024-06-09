#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                board[i][j][k] = ' ';
            }
        }
    }
}

void printBoard() {
    for (int k = 0; k < SIZE; k++) {
        printf("Layer %d:\n", k + 1);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%c ", board[i][j][k]);
                if (j < SIZE - 1) printf("| ");
            }
            printf("\n");
            if (i < SIZE - 1) {
                for (int j = 0; j < SIZE; j++) {
                    printf("-- ");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}

bool isWin(char player) {
    // Check rows, columns, and layers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((board[i][j][0] == player && board[i][j][1] == player && board[i][j][2] == player) ||
                (board[i][0][j] == player && board[i][1][j] == player && board[i][2][j] == player) ||
                (board[0][i][j] == player && board[1][i][j] == player && board[2][i][j] == player)) {
                return true;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0][0] == player && board[i][1][1] == player && board[i][2][2] == player) ||
            (board[i][0][2] == player && board[i][1][1] == player && board[i][2][0] == player) ||
            (board[0][i][0] == player && board[1][i][1] == player && board[2][i][2] == player) ||
            (board[0][i][2] == player && board[1][i][1] == player && board[2][i][0] == player) ||
            (board[0][0][i] == player && board[1][1][i] == player && board[2][2][i] == player) ||
            (board[0][2][i] == player && board[1][1][i] == player && board[2][0][i] == player)) {
            return true;
        }
    }

    // Check 3D diagonals
    if ((board[0][0][0] == player && board[1][1][1] == player && board[2][2][2] == player) ||
        (board[0][0][2] == player && board[1][1][1] == player && board[2][2][0] == player) ||
        (board[0][2][0] == player && board[1][1][1] == player && board[2][0][2] == player) ||
        (board[2][0][0] == player && board[1][1][1] == player && board[0][2][2] == player)) {
        return true;
    }

    return false;
}

bool isFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (board[i][j][k] == ' ') {
                    return false;
                }
            }
        }
    }
    return true;
}

void makeMove(char player) {
    int x, y, z;
    while (true) {
        printf("Player %c, enter your move : ", player);
        scanf("%d %d %d", &x, &y, &z);
        if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE && z >= 1 && z <= SIZE && board[x-1][y-1][z-1] == ' ') {
            board[x-1][y-1][z-1] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void playGame() {
    char player = 'X';
    initializeBoard();
    while (true) {
        printBoard();
        makeMove(player);
        if (isWin(player)) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        } else if (isFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    playGame();
    return 0;
}

