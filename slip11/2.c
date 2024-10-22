// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String: 0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1
// Implement FIFO

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

void FIFOPageReplacement(int pages[], int n, int frames) {
    int memory[MAX_FRAMES], pageFaults = 0, index = 0;
    int i, j, flag, count = 0;

    // Initialize memory frames
    for (i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    printf("Page Reference\tMemory Frames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                flag = 1; // Page hit
                break;
            }
        }

        // If page is not found, replace using FIFO
        if (flag == 0) {
            memory[index] = pages[i]; // Replace the oldest page
            index = (index + 1) % frames; // Update index for FIFO
            pageFaults++;

            // Print current memory state
            printf("%d\t\t", pages[i]);
            for (j = 0; j < frames; j++) {
                printf("%d ", memory[j]);
            }
            printf("\n");
        } else {
            // Print current memory state (no page fault)
            printf("%d\t\t", pages[i]);
            for (j = 0; j < frames; j++) {
                printf("%d ", memory[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1}; // Reference string
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames;

    printf("Enter number of memory frames: ");
    scanf("%d", &frames);

    if (frames > MAX_FRAMES) {
        printf("Maximum number of frames is %d\n", MAX_FRAMES);
        return 1;
    }

    FIFOPageReplacement(pages, n, frames);

    return 0;
}
