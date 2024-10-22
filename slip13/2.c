// Q.1 Write a program that demonstrates the use of nice() system call. After a child process is
// started using fork(), assign higher priority to the child using nice() system call.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    
    // Create a new child process using fork()
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child Process - PID: %d\n", getpid());

        // Assign higher priority using nice() system call
        int priority = nice(-10);  // Reducing the nice value increases priority (-20 is highest priority)
        if (priority == -1) {
            perror("Failed to set priority");
            exit(1);
        }
        printf("Child Process - New Priority: %d\n", priority);
        
        // Simulate some workload
        for (int i = 0; i < 5; i++) {
            printf("Child working %d\n", i);
            sleep(1);
        }
    } else {
        // Parent process
        printf("Parent Process - PID: %d\n", getpid());
        
        // Wait for the child to finish
        wait(NULL);
        printf("Child finished\n");
    }
    
    return 0;
}
