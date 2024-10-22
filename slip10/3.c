// Q.2 Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU
// burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define I/O_WAIT_TIME 2

// Structure to hold process details
typedef struct {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateTimes(Process processes[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int completionTime[MAX_PROCESSES];
    int startTime[MAX_PROCESSES];

    // Calculate completion and turnaround times
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            startTime[i] = processes[i].arrivalTime;
        } else {
            startTime[i] = completionTime[i - 1] + I/O_WAIT_TIME; // Include I/O wait time
        }
        completionTime[i] = startTime[i] + processes[i].burstTime;
        processes[i].turnaroundTime = completionTime[i] - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Print Gantt Chart
    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);
    }
    printf("|\n");
    for (int i = 0; i < n; i++) {
        printf("%d     ", startTime[i]);
    }
    printf("%d\n", completionTime[n - 1]);

    // Print times
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    // Print average times
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    // Seed for random number generation
    srand(time(0));

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    // Input processes
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrivalTime);
        processes[i].burstTime = rand() % 10 + 1; // Random burst time between 1 and 10
        printf("Assigned Burst Time for Process %d: %d\n", processes[i].id, processes[i].burstTime);
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    calculateTimes(processes, n); // Calculate and print times
    return 0;
}
