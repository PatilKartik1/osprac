// Q.2 Write the program to simulate Non-preemptive Priority scheduling. The arrival time and first
// CPU burst and priority for different n number of processes should be input to the algorithm.
// Assume the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly.
// The output should give Gantt chart, turnaround time and waiting time for each process. Also find
// the average waiting time and turnaround time..

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0, current_time = 0;

    // Calculate waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        
        // Update current time after finishing this process
        current_time += processes[i].burst_time + 2; // Adding I/O wait time
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void printGanttChart(Process processes[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);
    }
    printf("|\n0 ");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        current_time += processes[i].burst_time + 2; // Including I/O time
        printf("%d ", current_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time, burst time and priority for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }

    // Sort processes based on arrival time and then by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((processes[i].arrival_time > processes[j].arrival_time) ||
                (processes[i].arrival_time == processes[j].arrival_time && 
                 processes[i].priority > processes[j].priority)) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    calculateTimes(processes, n);
    printGanttChart(processes, n);

    return 0;
}
