#include <stdio.h>
int main() {
    int n, i, j;
    float avg_waiting_time = 0;
    printf("Welcome to FCFS");	
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n], arrival_time[n], burst_time[n];
   int waiting_time[n]; 
    for(i = 1; i <= n; i++){
    	process[i-1]=i;
    }	
	    for (i = 0; i < n; i++) {
        printf("For Process %d\n", process[i]);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("\n");
    }
    
     // Sort the processes by arrival time in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j]) {
            	// Swap the process numbers
            	int tem = process[i];
            	process[i] = process [j];
            	process[j] = tem;
                // Swap arrival time
                int temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;
                // Swap burst time
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    waiting_time[0] = 0;
    int t1 = arrival_time[0] + burst_time[0];
    for (i = 1; i < n; i++) {
        waiting_time[i] = t1 - arrival_time[i];
        t1 += burst_time[i];
       }

    // Calculate average waiting time
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
    avg_waiting_time /= n;
    // Display the table
    printf("Following is the execution of processes:");
    for (i = 0; i < n; i++) {
        printf("P%d\n", process[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    return 0;
}
	
