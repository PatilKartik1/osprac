// Q.1 Write a program that demonstrates the use of nice() system call. After a child process is started
// using fork(), assign higher priority to the child using nice() system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    // Create a child process
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        perror("Fork failed");.
        exit(1);
    } else if (pid == 0) {
        // Child process
        int current_nice = nice(0); // Get current nice value
        printf("Child Process: Current nice value: %d\n", current_nice);
        
        // Set a higher priority for the child process by decreasing the nice value
        if (nice(-5) == -1) {
            perror("Failed to set nice value");
            exit(1);
        }

        printf("Child Process: New nice value: %d\n", nice(0));
        
        // Simulate some work in the child process
        for (int i = 0; i < 5; i++) {
            printf("Child Process: Working... (%d)\n", i);
            sleep(1);
        }
    } else {
        // Parent process
        printf("Parent Process: PID of child: %d\n", pid);
        
        // Simulate some work in the parent process
        for (int i = 0; i < 5; i++) {
            printf("Parent Process: Working... (%d)\n", i);
            sleep(1);
        }

        // Wait for the child process to finish
        wait(NULL);
        printf("Parent Process: Child completed.\n");
    }

    return 0;
}
