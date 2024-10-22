// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n=3 as
// the number of memory frames.
// Reference String :3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
// Implement FIFO

#include <stdio.h>

int isPageInMemory(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void displayFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int frames[3] = {-1, -1, -1};  // Initialize frames to -1 (empty)
    int totalFaults = 0;
    int nextReplaceIndex = 0;

    printf("Page reference string: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n\nPage scheduling:\n");

    for (int i = 0; i < n; i++) {
        int currentPage = referenceString[i];

        if (!isPageInMemory(frames, 3, currentPage)) {
            // Page fault, replace the oldest page in FIFO manner
            frames[nextReplaceIndex] = currentPage;
            nextReplaceIndex = (nextReplaceIndex + 1) % 3;
            totalFaults++;
        }

        displayFrames(frames, 3);  // Show the current frame contents
    }

    printf("\nTotal page faults: %d\n", totalFaults);

    return 0;
}
