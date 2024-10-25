// Q.1 Write the program to calculate minimum number of resources needed to avoid
// deadlock.

#include <stdio.h>

int main() {
    int P, M, minResources;
    
    printf("Enter the number of processes: ");
    scanf("%d", &P);
    
    printf("Enter the maximum resources required by any process: ");
    scanf("%d", &M);
    
    minResources = P * (M - 1) + 1;
    
    printf("The minimum number of resources required to avoid deadlock is: %d\n", minResources);
    
    return 0;
}
