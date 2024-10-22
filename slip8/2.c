// Q.2. Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n =3 as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int pageFaults(int pages[], int n, int frames) {
    int page_faults = 0;
    int frame[MAX_FRAMES] = {-1, -1, -1};  // Initialize frames to -1 (empty)
    int index;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        // If not found, we have a page fault
        if (!found) {
            page_faults++;
            // If there is an empty frame, use it
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page;
                    found = 1;
                    break;
                }
            }

            // If no empty frame, replace the optimal page
            if (!found) {
                int farthest = -1, farthest_index;
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                farthest_index = j;
                            }
                            break;
                        }
                    }
                    // If the page is not found in future references
                    if (k == n) {
                        farthest_index = j;
                        break;
                    }
                }
                frame[farthest_index] = page;  // Replace the optimal page
            }
        }

        // Display current frame state
        printf("Frame state after accessing page %d: ", page);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("_ "); // Indicate empty frame
        }
        printf("\n");
    }

    return page_faults;
}

int main() {
    int pages[MAX_PAGES] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = MAX_FRAMES;

    int faults = pageFaults(pages, n, frames);
    printf("Total number of page faults: %d\n", faults);

    return 0;
}
