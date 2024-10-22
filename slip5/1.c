// Q.1 Write a program that demonstrates the use of nice () system call. After a child process is
// started using fork (), assign higher priority to the child using nice () system call

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int nice_value;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child Process (PID: %d) running\n", getpid());

        // Set higher priority for the child process
        nice_value = nice(-5); // Assigning higher priority
        if (nice_value == -1) {
            perror("Failed to change nice value");
            exit(EXIT_FAILURE);
        }

        printf("Child Process (PID: %d) new nice value: %d\n", getpid(), nice_value);
        // Simulating some workload in child process
        for (int i = 0; i < 5; i++) {
            printf("Child Process doing work %d...\n", i + 1);
            sleep(1); // Simulate work
        }
    } else {
        // Parent process
        printf("Parent Process (PID: %d) waiting for child...\n", getpid());
        wait(NULL); // Wait for child to finish
        printf("Parent Process (PID: %d) finished waiting for child.\n", getpid());
    }

    return 0;
}
