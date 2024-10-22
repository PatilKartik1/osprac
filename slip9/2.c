// Q.2 Write the program to simulate Round Robin (RR) scheduling. The arrival time and first CPUburst for different n number of processes should be input to the algorithm. Also give the time
// quantum as input. Assume the fixed IO waiting time (2 units). The next CPU-burst should be
// generated randomly. The output should give Gantt chart, turnaround time and waiting time for each
// process. Also find the average waiting time and turnaround time.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int cpu_burst;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process processes[], int n, int quantum) {
    int time = 0, completed = 0;
    int gantt_chart[MAX_PROCESSES * 2]; // Store Gantt chart information
    int gantt_index = 0;

    while (completed < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                found = true;
                int time_slice = (processes[i].remaining_time < quantum) ? processes[i].remaining_time : quantum;

                // Update time and remaining time
                processes[i].remaining_time -= time_slice;
                time += time_slice;
                gantt_chart[gantt_index++] = processes[i].id; // Add process to Gantt chart

                // If process is finished
                if (processes[i].remaining_time == 0) {
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].cpu_burst;
                    completed++;
                }

                // Simulate I/O wait time of 2 units if needed
                if (processes[i].remaining_time > 0) {
                    time += 2; // Fixed I/O waiting time
                }
            }
        }
        // If no process is found in this cycle, advance time
        if (!found) time++;
    }

    // Print Gantt chart
    printf("Gantt Chart: ");
    for (int i = 0; i < gantt_index; i++) {
        printf("P%d ", gantt_chart[i]);
    }
    printf("\n");
}

void printProcessTimes(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess ID\tArrival Time\tCPU Burst\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
               processes[i].cpu_burst, processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum number of processes.\n");
        return 1;
    }

    // Seed for random number generation
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time and CPU burst for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].cpu_burst);
        processes[i].remaining_time = processes[i].cpu_burst; // Initialize remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Calculate times
    calculateTimes(processes, n, quantum);
    printProcessTimes(processes, n);

    return 0;
}
