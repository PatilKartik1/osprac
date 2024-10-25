// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n=3 as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int capacity) {
    int farthest = index, res = -1;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return (res == -1) ? 0 : res;
}

int isInMemory(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity], pageFaults = 0;
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (!isInMemory(frames, capacity, pages[i])) {
            if (i < capacity) {
                frames[i] = pages[i];
            } else {
                int index = findOptimal(pages, frames, n, i, capacity);
                frames[index] = pages[i];
            }
            pageFaults++;
        }

        // Display current frame status
        printf("\nFrames after accessing page %d: ", pages[i]);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    optimalPageReplacement(pages, n, capacity);

    return 0;
}
