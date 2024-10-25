// Q. 1 Write a C program to accept the number of process and resources and find the need matrix
// content and display it.

#include <stdio.h>

// Function to calculate and display the need matrix
void calculateNeed(int need[][10], int max[][10], int allot[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

// Function to display the need matrix
void displayNeedMatrix(int need[][10], int n, int m) {
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);  // Input number of processes
    
    printf("Enter the number of resources: ");
    scanf("%d", &m);  // Input number of resource types

    int max[10][10], allot[10][10], need[10][10];

    // Input Maximum resource matrix
    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Allocated resource matrix
    printf("Enter the allocated resource matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Calculate the need matrix
    calculateNeed(need, max, allot, n, m);

    // Display the need matrix
    displayNeedMatrix(need, n, m);

    return 0;
}

