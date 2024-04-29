#include <stdio.h>

// Function to print the board configuration for the 4 Queens Problem
void printBoard(int board[4][4]) {
    printf("Board Configuration:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", board[i][j] ? 'Q' : '-');
        }
        printf("\n");
    }
}

int main() {
    // Sample board configuration for 4 Queens Problem
    int board[4][4] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 1, 0}
    };

    printBoard(board);

    return 0;
}
