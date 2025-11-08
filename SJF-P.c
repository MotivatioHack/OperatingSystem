#include <stdio.h>

int main() {
    int n, i, t = 0, completed = 0, min, pos;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], ct[n];

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time & Burst Time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(completed != n) {
        min = 9999;
        pos = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= t && rt[i] < min && rt[i] > 0) {
                min = rt[i];
                pos = i;
            }
        }

        if(pos == -1) {   // no process arrived yet
            t++;
            continue;
        }

        rt[pos]--;
        t++;

        if(rt[pos] == 0) {
            completed++;
            ct[pos] = t;
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    return 0;
}
