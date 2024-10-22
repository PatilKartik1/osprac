// Write the simulation program using SJF(non-preemptive). The arrival time and first CPU bursts of
// different jobs should be input to the system. The Assume the fixed I/O waiting time (2 units).Thenext
// CPU burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
    int id, arrival_time, cpu_burst, waiting_time, turnaround_time, completion_time;
};

void calculateTimes(struct Process p[], int n) {
    int complete = 0, t = 0, min_idx = 0;
    int is_complete[10] = {0}; // Tracks process completion

    while (complete != n) {
        int min_burst = 9999;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= t && is_complete[i] == 0 && p[i].cpu_burst < min_burst) {
                min_burst = p[i].cpu_burst;
                min_idx = i;
            }
        }

        // Execute the selected process
        t += p[min_idx].cpu_burst + 2; // Including fixed I/O waiting time of 2 units
        p[min_idx].completion_time = t;
        p[min_idx].turnaround_time = p[min_idx].completion_time - p[min_idx].arrival_time;
        p[min_idx].waiting_time = p[min_idx].turnaround_time - p[min_idx].cpu_burst;

        is_complete[min_idx] = 1;
        complete++;
    }
}

void printGanttChart(struct Process p[], int n) {
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[i].id);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("  %d  ", p[i].completion_time);
    }
    printf("\n");
}

void printResults(struct Process p[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time, p[i].cpu_burst, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    struct Process p[10];

    // Initialize random number generator
    srand(time(0));

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time of process P%d: ", p[i].id);
        scanf("%d", &p[i].arrival_time);

        printf("Enter first CPU burst of process P%d: ", p[i].id);
        scanf("%d", &p[i].cpu_burst);
    }

    // Calculate times and display results
    calculateTimes(p, n);
    printGanttChart(p, n);
    printResults(p, n);

    return 0;
}
