// Q.1 Write a program that demonstrates the use of nice() system call. After a child process is started
// using fork(), assign higher priority to the child using nice() system call.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    
    // Creating a child process
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child process ID: %d\n", getpid());
        
        // Changing the priority of the child process
        int priority = nice(-10);  // Assigning higher priority
        if (priority == -1) {
            perror("Nice failed");
        } else {
            printf("Child process priority set to: %d\n", priority);
        }
    }
    else {
        // Parent process waits for the child to complete
        wait(NULL);
        printf("Parent process ID: %d\n", getpid());
        printf("Child process finished execution\n");
    }
    
    return 0;
}
