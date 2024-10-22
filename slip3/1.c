// Q. 1 Creating a child process using the command exec(). Note down process ids of the parent
// and the child processes, check whether the control is given back to the parent after the child
// process terminates

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // This block executes in the child process
        printf("Child Process ID: %d\n", getpid());
        execlp("ls", "ls", NULL); // Replace child process with 'ls' command
        // If exec fails
        perror("Exec failed");
        exit(1);
    } 
    else {
        // This block executes in the parent process
        printf("Parent Process ID: %d\n", getpid());
        printf("Waiting for child to terminate...\n");
        wait(NULL); // Wait for the child to terminate
        printf("Child process terminated.\n");
    }

    return 0;
}
