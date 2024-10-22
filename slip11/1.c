// Q.1 Create a child process using fork(), display parent and child process id. Child process will
// display the message “Hello World” and the parent process should display “Hi”.

#include <stdio.h>
#include <unistd.h> // For fork()

int main() {
    pid_t pid; // Variable to store the process ID

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // This block executes in the child process
        printf("Hello World from Child Process! (PID: %d)\n", getpid());
    } else {
        // This block executes in the parent process
        printf("Hi from Parent Process! (PID: %d)\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}
