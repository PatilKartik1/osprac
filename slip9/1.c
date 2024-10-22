// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls”
// command.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls' command...\n", getpid());
        execl("/bin/ls", "ls", NULL); // Execute the 'ls' command
        // If execl fails
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent process (PID: %d) going to sleep...\n", getpid());
        sleep(5); // Sleep for 5 seconds
        printf("Parent process waking up.\n");
        wait(NULL); // Wait for child process to finish
    }

    return 0;
}
