// Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock() function)Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock() function)

#include <stdio.h>
#include <time.h>

void executeInstructions() {
    // Sample instructions (could be any operation)
    for (long i = 0; i < 100000000; i++) {
        // Simulating some computations
        // (This loop does nothing but can represent any processing)
    }
}

int main() {
    // Start time measurement
    clock_t start = clock();
    
    // Execute the set of instructions
    executeInstructions();
    
    // End time measurement
    clock_t end = clock();
    
    // Calculate time taken in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Execution Time: %f seconds\n", time_taken);
    
    return 0;
}
