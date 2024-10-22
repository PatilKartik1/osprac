// Q.2 Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU burst
// should be generated using random function. The output should give the Gantt chart,Turnaround
// Time and Waiting time for each process and average times. [20 marks]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;             // Process ID
    int arrivalTime;     // Arrival time
    int burstTime;       // CPU burst time
    int waitingTime;     // Waiting time
    int turnaroundTime;  // Turnaround time
} Process;

void calculateTimes(Process processes[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int completionTime[MAX_PROCESSES];

    completionTime[0] = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].turnaroundTime = completionTime[0] - processes[0].arrivalTime;
    processes[0].waitingTime = processes[0].turnaroundTime - processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        completionTime[i] = (completionTime[i - 1] > processes[i].arrivalTime) ? 
                            completionTime[i - 1] + processes[i].burstTime + 2 : 
                            processes[i].arrivalTime + processes[i].burstTime;

        processes[i].turnaroundTime = completionTime[i] - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\nGantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
    }
    printf("\n");

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", processes[i].pid, 
               processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].arrivalTime);
        processes[i].burstTime = rand() % 10 + 1; // Random burst time between 1 and 10
    }

    calculateTimes(processes, n);
    
    return 0;
}
