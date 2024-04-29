#include <stdio.h>
#include <stdbool.h>

#define N 8 // Number of queens (change N to solve for a different board size)

// Function to print the solution matrix
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check left side of this row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, return true
    if (col >= N) {
        return true;
    }

    // Try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen at board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1)) {
                return true; // If queen can be placed in next column, return true
            }

            // If placing queen at board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If queen can't be placed in any row in this column, return false
    return false;
}

// Function to solve N Queens problem
void solveNQueens() {
    int board[N][N] = { {0} };

    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist");
        return;
    }

    printf("Solution exists:\n");
    printSolution(board);
}

int main() {
    solveNQueens();
    return 0;
}
