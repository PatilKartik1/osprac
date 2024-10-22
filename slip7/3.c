// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String: 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
// i. Implement LRU

#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

// Function to find the index of the least recently used page
int findLRU(int time[], int n) {
    int minimum = time[0], index = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int frames, page_faults = 0, time[MAX_FRAMES];
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frame[MAX_FRAMES] = { -1 }; // Initialize frame with -1
    int n = sizeof(pages) / sizeof(pages[0]);

    printf("Enter the number of memory frames: ");
    scanf("%d", &frames);

    for (int i = 0; i < n; i++) {
        int flag = 0; // Flag to check if page is already in frame

        // Check if page is already in frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                time[j] = i; // Update time of the page
                break;
            }
        }

        // If page is not found in frame
        if (flag == 0) {
            int lru_index = findLRU(time, frames);
            frame[lru_index] = pages[i]; // Replace the least recently used page
            time[lru_index] = i; // Update time
            page_faults++;
        }

        // Display current frame status
        printf("Current frame status after referencing page %d: ", pages[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal number of page faults: %d\n", page_faults);
    return 0;
}
