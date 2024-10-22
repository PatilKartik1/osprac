// Q.1 [10] Write a program to illustrate the concept of orphan process ( Using fork() and
// sleep())

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Forking a new process
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) sleeping for 10 seconds...\n", getpid());
        sleep(10);
        printf("Parent process (PID: %d) exits.\n", getpid());
        exit(0);
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) created by parent (PID: %d).\n", getpid(), getppid());
        sleep(15); // Ensure parent terminates first, making child an orphan
        printf("Child process (PID: %d) is now orphan, adopted by init (new PPID: %d).\n", getpid(), getppid());
    } 
    else {
        // Fork failed
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}
