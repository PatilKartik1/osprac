// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls”
// command.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    // Create a child process using fork()
    pid = fork();

    if (pid < 0) {
        // Error occurred
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: Executing 'ls' command...\n");
        execl("/bin/ls", "ls", NULL);  // Execute the 'ls' command
    }
    else {
        // Parent process
        printf("Parent Process: Going to sleep...\n");
        sleep(5);  // Parent process sleeps
        printf("Parent Process: Awakened!\n");

        // Wait for child process to finish
        wait(NULL);
        printf("Parent Process: Child process finished.\n");
    }

    return 0;
}
