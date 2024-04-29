#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 knapsack problem using dynamic programming
int knapsack(int capacity, int weights[], int values[], int n) {
    // Create a 2D array to store the maximum value that can be obtained
    // for different capacities and different items
    int dp[n + 1][capacity + 1];

    // Initialize the first row and first column of the dp array to 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                // If the current item can be included, choose the maximum of including and excluding it
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                // If the current item cannot be included, exclude it
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The maximum value that can be obtained is stored in dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}
