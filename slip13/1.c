// Q2. Write the simulation program using SJF(non-preemptive). The arrival time and first CPU bursts of
// different jobsshould be input to the system. The Assume the fixed I/O waiting time (2 units).Thenext
// CPU burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a process
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to sort processes by arrival time and burst time
void sortByBurstTime(struct process proc[], int n, int time) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc[j].arrival_time <= time && proc[i].burst_time > proc[j].burst_time) {
                struct process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to generate random CPU burst times
int generateRandomBurstTime() {
    return rand() % 10 + 1;  // Random burst between 1 and 10 units
}

// SJF Scheduling Function
void sjfScheduling(struct process proc[], int n) {
    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    
    printf("\nGantt Chart:\n");
    
    for (int i = 0; i < n; i++) {
        sortByBurstTime(proc, n, currentTime);
        
        if (proc[i].arrival_time > currentTime) {
            currentTime = proc[i].arrival_time;
        }
        
        printf("P%d ", proc[i].pid);
        
        // Calculate waiting time and turnaround time
        proc[i].waiting_time = currentTime - proc[i].arrival_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        
        currentTime += proc[i].burst_time;
        
        totalWaitingTime += proc[i].waiting_time;
        totalTurnaroundTime += proc[i].turnaround_time;
        
        // Simulate fixed I/O waiting time (2 units) and next random CPU burst
        currentTime += 2;  // I/O waiting time
        proc[i].burst_time = generateRandomBurstTime();
    }
    
    // Output waiting times and turnaround times
    printf("\n\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", proc[i].pid, proc[i].waiting_time, proc[i].turnaround_time);
    }
    
    // Calculate and display average times
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process proc[n];
    
    for (int i = 0; i < n; i++) {
        proc[i].pid = i+1;
        printf("Enter arrival time for process P%d: ", i+1);
        scanf("%d", &proc[i].arrival_time);
        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &proc[i].burst_time);
    }
    
    sjfScheduling(proc, n);
    
    return 0;
}
