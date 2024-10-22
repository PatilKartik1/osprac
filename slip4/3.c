// Q2. Write a C program to simulate Banker’s algorithm for the purpose of deadlock avoidance.
// Consider the following snapshot of system, A, B, C and D are the resource type.

#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 4 // Number of resources

void calculateNeed(int need[P][R], int max[P][R], int alloc[P][R]) {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

bool isSafe(int processes[], int avail[], int max[][R], int alloc[][R]) {
    int need[P][R];
    calculateNeed(need, max, alloc);

    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");
    return true;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};

    int avail[] = {1, 5, 2, 0}; // Available resources A, B, C, D

    int max[P][R] = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 3, 2},
        {0, 6, 5, 6}};

    int alloc[P][R] = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4}};

    isSafe(processes, avail, max, alloc);
    return 0;
}
