// Partially implement the Menu driven Banker's algorithm for accepting Allocation, Max from
// user.
// a) Accept Available
// b) Display Allocation, Max
// c) Find Need and display It,
// d) Display Available Consider the system with 3 resources types A,B, and C with 7,2,6
// instances respectively.
// Consider the following snapshot:

#include <stdio.h>

int n = 5, m = 3; // Number of processes and resources
int allocation[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 3}, {2, 1, 1}, {0, 0, 2} };
int max[5][3] = { {0, 0, 0}, {2, 0, 0}, {0, 0, 1}, {1, 0, 0}, {0, 0, 2} };
int available[3] = { 7, 2, 6 };

// Function to display Allocation matrix
void displayAllocation() {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
}

// Function to display Max matrix
void displayMax() {
    printf("Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate and display Need matrix
void displayNeed() {
    int need[5][3];
    printf("Need Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

// Function to display Available matrix
void displayAvailable() {
    printf("Available Resources:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Allocation\n");
        printf("2. Display Max\n");
        printf("3. Display Need\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllocation();
                break;
            case 2:
                displayMax();
                break;
            case 3:
                displayNeed();
                break;
            case 4:
                displayAvailable();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
