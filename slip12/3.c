// Q2. Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU burst
// should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times.

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void findWaitingTime(struct Process processes[], int n) {
    int service_time[n];
    service_time[0] = processes[0].arrival_time;
    processes[0].waiting_time = 0;
    
    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + processes[i - 1].burst_time + 2; // 2 units I/O waiting time
        processes[i].waiting_time = service_time[i] - processes[i].arrival_time;
        
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }
    }
}

void findTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void findAverageTimes(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, 
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage waiting time = %.2f", (float)total_waiting_time / n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_turnaround_time / n);
}

void generateRandomBurstTimes(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].burst_time = rand() % 10 + 1;  // Random burst time between 1 and 10
    }
}

void printGanttChart(struct Process processes[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].pid);
    }
    printf("|\n");

    int time = processes[0].arrival_time;
    for (int i = 0; i < n; i++) {
        printf("%d    ", time);
        time += processes[i].burst_time + 2; // Adding fixed I/O waiting time
    }
    printf("%d\n", time);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }
    
    generateRandomBurstTimes(processes, n);

    findAverageTimes(processes, n);
    printGanttChart(processes, n);

    return 0;
}
