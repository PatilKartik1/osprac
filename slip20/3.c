// Q2. Write the simulation program using FCFS. The arrival time and first CPU bursts of different jobs
// should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU burst
// should be generated using random function. The output should give the Gantt chart, Turnaround
// Time and Waiting time for each process and average times.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10 // Maximum number of processes

typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // CPU burst time
    int wait;       // Waiting time
    int turnaround; // Turnaround time
} Process;

// Function to calculate waiting and turnaround times
void calculateTimes(Process processes[], int n) {
    int total_wait = 0, total_turnaround = 0;
    processes[0].wait = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].wait = processes[i - 1].wait + processes[i - 1].burst + 2; // Include I/O wait
        total_wait += processes[i].wait;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].wait + processes[i].burst;
        total_turnaround += processes[i].turnaround;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst, processes[i].wait, processes[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wait / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

// Function to generate random CPU burst times
int randomBurst() {
    return (rand() % 5) + 1; // Random burst time between 1 and 5
}

int main() {
    srand(time(0)); // Seed for random number generation
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    // Input for arrival time and first CPU bursts
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        processes[i].burst = randomBurst(); // Generate random CPU burst
        printf("Generated Burst Time for Process %d: %d\n", i + 1, processes[i].burst);
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival > processes[j + 1].arrival) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate times
    calculateTimes(processes, n);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);
    }
    printf("|\n");

    return 0;
}
