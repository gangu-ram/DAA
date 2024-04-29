#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// A utility function to sort items based on value/weight ratio in non-increasing order
int compare(const void *a, const void *b) {
    double ratio1 = ((double)((struct Item *)a)->value / (double)((struct Item *)a)->weight);
    double ratio2 = ((double)((struct Item *)b)->value / (double)((struct Item *)b)->weight);
    return ratio2 > ratio1 ? 1 : -1;
}

// Function to solve Fractional Knapsack problem using Greedy method
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items based on value/weight ratio
    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding item won't overflow, add it completely
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // If we can't add current item fully, add fraction of it
            int remaining = W - currentWeight;
            finalValue += arr[i].value * ((double)remaining / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);

    struct Item arr[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
