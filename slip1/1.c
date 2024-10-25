// Q.1 Write a program that demonstrates the use of nice() system call. After a child process is started
// using fork(), assign higher priority to the child using nice() system call.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int priority;

    // Create a new process using fork
    pid = fork();

    if (pid < 0) {
        // Error occurred in fork
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());
        
        // Assign higher priority to the child process using nice()
        priority = nice(-10);  // Increase priority by -10
        if (priority == -1) {
            printf("Error changing priority.\n");
        } else {
            printf("Child Process: New Priority = %d\n", priority);
        }

    } else {
        // Parent process
        wait(NULL);  // Wait for the child to complete
        printf("Parent Process: Child complete.\n");
    }

    return 0;
}

