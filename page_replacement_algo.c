#include <stdio.h>

int main() {
    int n, f, i, j, k, pageFaults;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for(i=0;i<n;i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames (>=3): ");
    scanf("%d", &f);

    int frame[f];

    // =========================== FCFS ===========================
    for(i=0;i<f;i++) frame[i] = -1;
    pageFaults = 0;
    int idx = 0;

    printf("\nFCFS Page Replacement:\n");
    for(i=0;i<n;i++){
        int found = 0;

        for(j=0;j<f;j++)
            if(frame[j] == pages[i])
                found = 1;

        if(!found){
            frame[idx] = pages[i];
            idx = (idx + 1) % f;
            pageFaults++;
        }

        for(j=0;j<f;j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total Page Faults (FCFS): %d\n", pageFaults);


    // =========================== LRU ===========================
    for(i=0;i<f;i++) frame[i] = -1;
    pageFaults = 0;

    printf("\nLRU Page Replacement:\n");
    for(i=0;i<n;i++){
        int found = 0;

        for(j=0;j<f;j++)
            if(frame[j] == pages[i])
                found = 1;

        if(!found){
            int least = 9999, pos = -1;

            for(j=0;j<f;j++){
                int used = 0;
                for(k=i-1;k>=0;k--){
                    if(frame[j] == pages[k]){
                        used = i - k;
                        break;
                    }
                }
                if(used < least){
                    least = used;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            pageFaults++;
        }

        for(j=0;j<f;j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total Page Faults (LRU): %d\n", pageFaults);


    // =========================== OPTIMAL ===========================
    for(i=0;i<f;i++) frame[i] = -1;
    pageFaults = 0;

    printf("\nOptimal Page Replacement:\n");
    for(i=0;i<n;i++){
        int found = 0;

        for(j=0;j<f;j++)
            if(frame[j] == pages[i])
                found = 1;

        if(!found){
            int farthest = -1, pos = -1;

            for(j=0;j<f;j++){
                int next = 9999;
                for(k=i+1;k<n;k++){
                    if(frame[j] == pages[k]){
                        next = k;
                        break;
                    }
                }
                if(next > farthest){
                    farthest = next;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            pageFaults++;
        }

        for(j=0;j<f;j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total Page Faults (Optimal): %d\n", pageFaults);

    return 0;
}
