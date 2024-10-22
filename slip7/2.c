// Q.2 Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU
// burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
} Process;

void calculateTimes(Process processes[], int n, int io_wait) {
    int total_waiting_time = 0, total_turnaround_time = 0, completion_time[MAX_PROCESSES];
    
    completion_time[0] = processes[0].arrival_time + processes[0].burst_time;

    // Calculate completion time for each process
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + io_wait + processes[i].burst_time;
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = completion_time[i] - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Display results
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].id);
    }
    printf("\n");

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n, io_wait = 2;
    Process processes[MAX_PROCESSES];

    srand(time(0)); // Seed for random number generation

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and first burst time
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time of Process P%d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        processes[i].burst_time = rand() % 10 + 1; // Generate random burst time between 1 and 10
        printf("Generated Burst Time for Process P%d: %d\n", processes[i].id, processes[i].burst_time);
    }

    // Calculate and display times
    calculateTimes(processes, n, io_wait);

    return 0;
}
