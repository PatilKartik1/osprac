// Q.2 Write the simulation program to implement demand paging and show the page scheduling and
// total number of page faults for the following given page reference string. Give input n=3 as the
// number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>

#define MAX_FRAMES 3 // Define maximum number of frames

// Function to find the optimal page to replace
int findOptimal(int pages[], int frame[], int m, int n) {
    int optimalIndex = -1;
    int farthest = -1;
    
    for (int i = 0; i < m; i++) {
        int j;
        for (j = n; j < 10; j++) {
            if (frame[i] == pages[j]) {
                // If the page is found in frame
                if (j > farthest) {
                    farthest = j;
                    optimalIndex = i;
                }
                break;
            }
        }
        // If the page is not found in the future references
        if (j == 10) {
            return i; // Return this index to replace
        }
    }
    return optimalIndex; // Return the optimal index to replace
}

void demandPaging(int pages[], int n, int m) {
    int frame[MAX_FRAMES]; // Memory frames
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < m; i++) {
        frame[i] = -1; // Empty frame
    }

    // Process each page reference
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (frame[j] == pages[i]) {
                break; // Page is already in frame
            }
        }

        if (j == m) { // Page fault occurs
            pageFaults++;
            int replaceIndex = findOptimal(pages, frame, m, i);
            frame[replaceIndex] = pages[i]; // Replace page
        }

        // Print current frame status
        printf("Page Reference: %d | Frames: ", pages[i]);
        for (int k = 0; k < m; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8}; // Page reference string
    int n = sizeof(pages) / sizeof(pages[0]); // Number of pages
    int m = MAX_FRAMES; // Number of frames

    demandPaging(pages, n, m); // Call the demand paging function
    return 0;
}
