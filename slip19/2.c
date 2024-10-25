// Q.2 Write the program to simulate Non-preemptive Priority scheduling. The arrival time and
// first CPU burst and priority for different n number of processes should be input to the algorithm.
// Assume the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly.
// The output should give Gantt chart, turnaround time and waiting time for each process. Also find
// the average waiting time and turnaround time.

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;  // Process ID
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].waiting_time = 0; // First process has 0 waiting time
    
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time + 2; // IO waiting time of 2 units
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void sortByPriority(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void printGanttChart(struct Process proc[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", proc[i].pid);
    }
    printf("|\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].arrival_time, &proc[i].burst_time, &proc[i].priority);
    }

    // Sort processes by priority
    sortByPriority(proc, n);

    // Calculate waiting and turnaround times
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    // Print Gantt Chart
    printGanttChart(proc, n);

    // Calculate and print waiting and turnaround times
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    return 0;
}
