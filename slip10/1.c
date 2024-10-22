// Q.1 Write a program to illustrate the concept of orphan process (Using fork() and sleep())

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(5); // Simulate some work in the child process
        printf("Child Process: PID = %d, I am now orphaned! My new Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent Process: PID = %d, I will terminate now.\n", getpid());
        exit(0); // Terminate parent process
    }

    return 0; // Both processes will reach here
}
