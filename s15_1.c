#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // Maximum number of items
#define MAX_WEIGHT 1000 // Maximum weight capacity of knapsack

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to compare two items based on their value per unit weight
int compare(const void* a, const void* b) {
    double ratio1 = ((double)((struct Item*)b)->value / ((struct Item*)b)->weight);
    double ratio2 = ((double)((struct Item*)a)->value / ((struct Item*)a)->weight);
    return ratio1 - ratio2;
}

// LCBB function to find the optimal solution for 0/1 knapsack problem
void LCBB(struct Item items[], int n, int capacity) {
    // Sort items based on value per unit weight (decreasing order)
    qsort(items, n, sizeof(struct Item), compare);

    // Initialize variables for tracking best solution
    int totalWeight = 0;
    int totalValue = 0;

    // Initialize variables for branch and bound algorithm
    int currentWeight = 0;
    int currentValue = 0;
    int level = 0;

    // Array to store if item is included or not (1 for included, 0 for not included)
    int solution[MAX_ITEMS];

    // Initialize solution array
    for (int i = 0; i < n; i++) {
        solution[i] = 0;
    }

    // Loop to perform branch and bound
    while (level != -1) {
        // Check if we reached leaf node
        if (level == n) {
            if (currentValue > totalValue) {
                totalValue = currentValue;
                totalWeight = currentWeight;
                for (int i = 0; i < n; i++) {
                    solution[i] = items[i].weight;
                }
            }
            level--;
            continue;
        }

        // Check if item can be included
        if (currentWeight + items[level].weight <= capacity) {
            currentWeight += items[level].weight;
            currentValue += items[level].value;
        } else {
            level--;
        }

        // Calculate upper bound
        double bound = currentValue;
        int remainingWeight = capacity - currentWeight;
        int j = level + 1;
        while (remainingWeight > 0 && j < n) {
            if (items[j].weight <= remainingWeight) {
                bound += items[j].value;
                remainingWeight -= items[j].weight;
            } else {
                bound += items[j].value * ((double)remainingWeight / items[j].weight);
                remainingWeight = 0;
            }
            j++;
        }

        // If upper bound is less than best solution so far, backtrack
        if (bound <= totalValue) {
            level--;
            continue;
        }

        // Move to next level
        level++;
    }

    // Print the best solution found
    printf("Optimal solution: Total value = %d, Total weight = %d\n", totalValue, totalWeight);
    printf("Items included:\n");
    for (int i = 0; i < n; i++) {
        if (solution[i] != 0) {
            printf("Item %d: Weight = %d, Value = %d\n", i+1, items[i].weight, items[i].value);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[MAX_ITEMS];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    LCBB(items, n, capacity);

    return 0;
}
