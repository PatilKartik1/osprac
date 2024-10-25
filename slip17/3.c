// Q2.Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next
// CPU burst should be generated using random function. The output should give the Gantt
// chart, Turnaround Time and Waiting time for each process and average
// times.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

void calculateTimes(struct Process proc[], int n, int ioWaitTime) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    int currentTime = 0;
    
    printf("\nGantt Chart:\n");
    
    for (int i = 0; i < n; i++) {
        if (currentTime < proc[i].arrivalTime) {
            currentTime = proc[i].arrivalTime;
        }

        // Start executing the process
        printf("| P%d ", proc[i].pid);
        currentTime += proc[i].burstTime;

        // Calculate waiting and turnaround time
        proc[i].turnAroundTime = currentTime - proc[i].arrivalTime;
        proc[i].waitingTime = proc[i].turnAroundTime - proc[i].burstTime;
        
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;

        // Adding fixed I/O waiting time
        currentTime += ioWaitTime;
    }
    printf("|\n");

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrivalTime, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    srand(time(0));  // Seed for random number generation
    int n, ioWaitTime = 2;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &proc[i].arrivalTime);
        
        // Random CPU burst time (1 to 10 units)
        proc[i].burstTime = rand() % 10 + 1;
    }

    // Sort processes by arrival time (FCFS scheduling)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrivalTime > proc[j + 1].arrivalTime) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    calculateTimes(proc, n, ioWaitTime);

    return 0;
}
