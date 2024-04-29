#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
    float ratio; // Value-to-weight ratio
};

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

// Function to solve the Fractional Knapsack problem using Greedy method
float fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items based on their value-to-weight ratio in non-increasing order
    qsort(items, n, sizeof(items[0]), compare);

    float totalValue = 0; // Total value of items taken in the knapsack
    int remainingCapacity = capacity; // Remaining capacity of the knapsack

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If the item can be taken fully, take it and update remaining capacity
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else { // If the item cannot be taken fully, take a fraction of it
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity; // Capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n]; // Array to store items

    // Input items (value and weight)
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    // Calculate and print the maximum value that can be obtained in the knapsack
    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
