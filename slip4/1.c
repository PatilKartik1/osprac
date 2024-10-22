// Q.1 Write a program to illustrate the concept of orphan process ( Using fork() and sleep())
// [10 marks]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a new process

    if (child_pid < 0) {
        // Error in fork
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(5); // Simulate work by sleeping for 5 seconds
        printf("Child Process: My parent has terminated. I am now an orphan. PID = %d\n", getpid());
    } else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
        sleep(2); // Parent sleeps for 2 seconds before terminating
        printf("Parent Process: Terminating now.\n");
        exit(0); // Parent terminates
    }

    return 0;
}
