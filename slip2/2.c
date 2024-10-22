// Q.2 Write the simulation program using SJF (non-preemptive). The arrival time and first CPU
// bursts of different jobs should be input to the system. Assume the fixed I/O waiting time (2 units).
// The next CPU burst should be generated using random function. The output should give the Gantt
// chart, Turnaround Time and Waiting time for each process and average times.[20
// marks]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process p[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time) {
            time = p[i].arrival_time;
        }
        p[i].waiting_time = time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;

        time += p[i].burst_time + 2; // I/O wait time
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void sortProcesses(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burst_time > p[j + 1].burst_time) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    Process p[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and initial CPU burst for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].id = i + 1; // Process ID
    }

    // Sort processes by arrival time initially
    sortProcesses(p, n);
    // Sort processes by burst time for SJF
    sortProcesses(p, n);

    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i].id);
    }
    printf("|\n");

    // Calculate and display times
    calculateTimes(p, n);

    return 0;
}
