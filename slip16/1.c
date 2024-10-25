// Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock()
// function)

#include <stdio.h>
#include <time.h>

int main() {
    // Declare variables to store the start and end time
    clock_t start, end;
    double cpu_time_used;

    // Record the start time
    start = clock();

    // Set of instructions whose execution time is to be measured
    for (int i = 0; i < 100000000; i++) {
        // Simple instructions, e.g., summing numbers
        int sum = i + 1;
    }

    // Record the end time
    end = clock();

    // Calculate the time taken by subtracting start from end
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
