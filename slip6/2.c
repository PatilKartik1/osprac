// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String :3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
// Implement FIFO

#include <stdio.h>

#define MAX_FRAMES 10 // Maximum number of frames

// Function to check if a page is already in memory
int isPageInMemory(int page, int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1; // Page is in memory
        }
    }
    return 0; // Page is not in memory
}

// FIFO Page Replacement Algorithm
void fifoPageReplacement(int reference[], int n, int numFrames) {
    int frames[MAX_FRAMES];
    int pageFaults = 0, nextFrame = 0;

    // Initialize frames to -1
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    printf("Page Replacement Order:\n");

    for (int i = 0; i < n; i++) {
        int currentPage = reference[i];

        // Check if page is already in memory
        if (!isPageInMemory(currentPage, frames, numFrames)) {
            frames[nextFrame] = currentPage; // Replace the oldest page
            nextFrame = (nextFrame + 1) % numFrames; // Move to next frame

            // Count page fault and display frames
            pageFaults++;
            printf("Page Fault: %d, Frames: ", currentPage);
            for (int j = 0; j < numFrames; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        } else {
            printf("Page Hit: %d, Frames: ", currentPage);
            for (int j = 0; j < numFrames; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    // Reference string
    int reference[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int numFrames;

    // Input number of frames
    printf("Enter number of memory frames: ");
    scanf("%d", &numFrames);

    // Execute FIFO page replacement
    fifoPageReplacement(reference, sizeof(reference) / sizeof(reference[0]), numFrames);

    return 0;
}
