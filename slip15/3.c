// Q2. Write the program to simulate Preemptive Shortest Job First (SJF) -scheduling. The arrival time and
// first CPU-burst for different n number of processes should be input to the algorithm. Assumethe
// fixed IO waiting time (2 units). The nextCPU-burstshould be generated randomly. The outputshould
// give Gantt chart, turnaround time and waiting time for each process. Also find the averagewaiting
// time and turnaround time.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process proc[], int n, int fixed_io_time) {
    int total_time = 0, completed = 0, current_time = 0;
    int min_burst_index, shortest_remaining;
    int waiting_time_total = 0, turnaround_time_total = 0;
    int gantt_chart[1000], gantt_time[1000], gantt_pos = 0;

    while (completed != n) {
        min_burst_index = -1;
        shortest_remaining = INT_MAX;

        // Find the process with the shortest remaining time at current_time
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].remaining_time > 0 &&
                proc[i].remaining_time < shortest_remaining) {
                shortest_remaining = proc[i].remaining_time;
                min_burst_index = i;
            }
        }

        if (min_burst_index != -1) {
            gantt_chart[gantt_pos] = proc[min_burst_index].pid;
            gantt_time[gantt_pos++] = current_time;

            // Simulate the process execution
            current_time++;
            proc[min_burst_index].remaining_time--;

            if (proc[min_burst_index].remaining_time == 0) {
                completed++;
                proc[min_burst_index].turnaround_time = current_time - proc[min_burst_index].arrival_time;
                proc[min_burst_index].waiting_time = proc[min_burst_index].turnaround_time - proc[min_burst_index].burst_time;
                waiting_time_total += proc[min_burst_index].waiting_time;
                turnaround_time_total += proc[min_burst_index].turnaround_time;
            }
        } else {
            current_time++;
        }

        // Simulate fixed IO waiting time
        if (completed != 0 && completed % 2 == 0) {
            current_time += fixed_io_time;
        }
    }

    gantt_time[gantt_pos] = current_time;

    // Display Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gantt_pos; i++) {
        printf("| P%d (%d) ", gantt_chart[i], gantt_time[i]);
    }
    printf("|\n");

    // Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time,
               proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    // Display average times
    printf("\nAverage Waiting Time: %.2f\n", (float)waiting_time_total / n);
    printf("Average Turnaround Time: %.2f\n", (float)turnaround_time_total / n);
}

int main() {
    int n, fixed_io_time = 2;
    
    // Input the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    
    // Input process details
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process P%d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time;
    }

    // Simulate Preemptive SJF Scheduling
    calculateTimes(proc, n, fixed_io_time);

    return 0;
}
