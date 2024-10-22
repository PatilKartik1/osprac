// Q.1 Write a C program to accept the number of process and resources and find the need matrix
// content and display it


#include <stdio.h>

void calculateNeed(int processes[], int max[][10], int allot[][10], int need[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

void displayNeed(int need[][10], int n, int m) {
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
    
    // Accept number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int processes[n];
    int max[n][10], allot[n][10], need[n][10];

    // Input the process IDs
    for (int i = 0; i < n; i++) {
        processes[i] = i;
    }

    // Input the maximum resources required by each process
    printf("\nEnter the Maximum Resources Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Max[%d][%d]: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }

    // Input the allocated resources to each process
    printf("\nEnter the Allocated Resources Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Allot[%d][%d]: ", i, j);
            scanf("%d", &allot[i][j]);
        }
    }

    // Calculate the Need Matrix
    calculateNeed(processes, max, allot, need, n, m);

    // Display the Need Matrix
    displayNeed(need, n, m);

    return 0;
}
