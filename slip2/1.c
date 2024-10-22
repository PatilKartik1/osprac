// Q.1 Create a child process using fork(), display parent and child process id. Child process will
// display the message “Hello World” and the parent process should display “Hi”.
// [10 marks]

#include <stdio.h>
#include <unistd.h> // For fork()

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Error occurred
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello World\n");
        printf("Child Process ID: %d\n", getpid());
    } else {
        // Parent process
        printf("Hi\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }
    
    return 0;
}
