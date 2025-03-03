#include <stdio.h>

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], waiting_time[n], turn_around_time[n], remaining_time[n];
    int t = 0;

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Process %d: ", processes[i]);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }

    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turn_around_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("\nAverage waiting time: %.2f", total_waiting_time / n);
    printf("\nAverage turn around time: %.2f\n", total_turnaround_time / n);

    return 0;
}
