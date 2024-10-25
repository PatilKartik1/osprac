// Q2.Write the simulation program using SJF (non-preemptive). The arrival time and first CPU bursts of
// different jobs should be input to the system. The Assume the fixed I/O waiting time (2 units).Thenext
// CPU burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times. 

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define IO_WAIT 2  // Fixed I/O wait time

// Structure to hold process information
struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(struct Process p[], int n) {
    int currentTime = 0, completed = 0;
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    while (completed != n) {
        int idx = -1;
        int minBurst = 1e9;

        // Select the process with shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && p[i].burstTime < minBurst && p[i].completionTime == 0) {
                minBurst = p[i].burstTime;
                idx = i;
            }
        }

        // If a process is selected, schedule it
        if (idx != -1) {
            p[idx].startTime = currentTime;
            p[idx].completionTime = p[idx].startTime + p[idx].burstTime;
            p[idx].turnaroundTime = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;

            currentTime = p[idx].completionTime + IO_WAIT;  // Include I/O wait time
            totalTurnaroundTime += p[idx].turnaroundTime;
            totalWaitingTime += p[idx].waitingTime;
            completed++;
        } else {
            currentTime++;  // No process available; increment time
        }
    }

    // Display results
    printf("\nProcess\tArrival\tBurst\tStart\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, 
               p[i].startTime, p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}

int main() {
    int n;
    struct Process p[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and initial CPU burst time
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].completionTime = 0;  // Initialize completion time to 0
    }

    calculateTimes(p, n);

    return 0;
}
