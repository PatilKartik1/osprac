// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls”
// command

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create child process using fork()

    if (pid < 0) {
        // Fork failed
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process is executing 'ls' command.\n");
        execl("/bin/ls", "ls", NULL);  // Execute the 'ls' command using execl()
        printf("This line will not be printed if execl() is successful.\n");
    } else {
        // Parent process
        printf("Parent process going to sleep.\n");
        sleep(5);  // Parent process goes to sleep
        printf("Parent process awake.\n");
    }

    return 0;
}
