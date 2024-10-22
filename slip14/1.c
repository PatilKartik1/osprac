// Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock() function)

#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Start the clock
    start = clock();

    // Sample set of instructions (simple for-loop)
    for (int i = 0; i < 1000000; i++) {
        // Simple computation
        int x = i * i;
    }

    // End the clock
    end = clock();

    // Calculate the time taken in seconds
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Output the time taken
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
