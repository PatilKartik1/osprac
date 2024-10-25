// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String :7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
// Implement LRU

#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, frames[10], pages[30], counter = 0, time[10];
    int flag1, flag2, i, j, pos, pageFaults = 0;

    // Input number of memory frames
    printf("Enter number of memory frames: ");
    scanf("%d", &n);

    // Input the page reference string
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int totalPages = sizeof(referenceString) / sizeof(referenceString[0]);

    // Initialize frames to -1
    for (i = 0; i < n; ++i) {
        frames[i] = -1;
    }

    // LRU Page Replacement Simulation
    for (i = 0; i < totalPages; ++i) {
        flag1 = flag2 = 0;

        // Check if page is already in any frame
        for (j = 0; j < n; ++j) {
            if (frames[j] == referenceString[i]) {
                counter++;
                time[j] = counter;  // Update the time for LRU
                flag1 = flag2 = 1;
                break;
            }
        }

        // If the page is not in a frame
        if (flag1 == 0) {
            for (j = 0; j < n; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    pageFaults++;
                    frames[j] = referenceString[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame is found, replace the least recently used page
        if (flag2 == 0) {
            pos = findLRU(time, n);
            counter++;
            pageFaults++;
            frames[pos] = referenceString[i];
            time[pos] = counter;
        }

        // Display the current state of frames
        printf("\nFrames: ");
        for (j = 0; j < n; ++j) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
    }

    // Display the total number of page faults
    printf("\n\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
