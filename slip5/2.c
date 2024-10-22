// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames. Reference String: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
// i. Implement FIFO

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

void FIFOPageReplacement(int pages[], int n, int frames) {
    int frame[MAX_FRAMES], pageFaults = 0, k = 0;
    int isPageFound;

    // Initialize frames to -1 (empty)
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        isPageFound = 0;
        
        // Check if page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                isPageFound = 1;
                break;
            }
        }

        // If page not found, it's a page fault
        if (!isPageFound) {
            frame[k] = pages[i];
            k = (k + 1) % frames; // Move to the next frame in FIFO manner
            pageFaults++;

            // Print current frames
            printf("Page Fault! Frames: ");
            for (int j = 0; j < frames; j++) {
                if (frame[j] != -1) {
                    printf("%d ", frame[j]);
                }
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames;

    printf("Enter the number of memory frames: ");
    scanf("%d", &frames);

    if (frames > MAX_FRAMES) {
        printf("Error: Maximum number of frames is %d.\n", MAX_FRAMES);
        return 1;
    }

    FIFOPageReplacement(pages, n, frames);

    return 0;
}
