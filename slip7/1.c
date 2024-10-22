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
        exit(1);
    }

    if (pid == 0) {
        // This block is executed by the child process
        printf("Child Process: Executing 'ls' command...\n");
        execl("/bin/ls", "ls", NULL); // Execute the 'ls' command
        // If execl is successful, the following line won't execute
        perror("execl failed");
        exit(1);
    } else {
        // This block is executed by the parent process
        printf("Parent Process: Going to sleep...\n");
        sleep(5); // Sleep for 5 seconds
        printf("Parent Process: Woke up!\n");
        
        // Optionally wait for the child process to finish
        wait(NULL);
        printf("Parent Process: Child has finished execution.\n");
    }

    return 0;
}
