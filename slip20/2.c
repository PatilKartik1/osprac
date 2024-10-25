// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n=3 as
// the number of memory frames.
// Reference String : 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
// i. Implement LRU

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3 // Number of memory frames

// Function to check if a page is already in memory
int isPageInMemory(int page, int memory[], int frame_count) {
    for (int i = 0; i < frame_count; i++) {
        if (memory[i] == page) {
            return 1; // Page found
        }
    }
    return 0; // Page not found
}

// Function to find the index of the least recently used page
int getLRUPage(int time[], int frame_count) {
    int min = time[0], index = 0;
    for (int i = 1; i < frame_count; i++) {
        if (time[i] < min) {
            min = time[i];
            index = i;
        }
    }
    return index;
}

// LRU Page Replacement Algorithm
void lruPageReplacement(int pages[], int page_count) {
    int memory[MAX_FRAMES], time[MAX_FRAMES];
    int page_faults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        memory[i] = -1; // Initialize memory frames
        time[i] = 0; // Initialize time stamps
    }

    for (int i = 0; i < page_count; i++) {
        int current_page = pages[i];
        // If page is not in memory
        if (!isPageInMemory(current_page, memory, MAX_FRAMES)) {
            page_faults++;
            // Find the least recently used page
            int lru_index = getLRUPage(time, MAX_FRAMES);
            memory[lru_index] = current_page; // Replace LRU page
            time[lru_index] = i; // Update the time of the replaced page
            printf("Page fault: Loaded page %d into frame %d\n", current_page, lru_index);
        } else {
            printf("Page hit: Page %d is already in memory\n", current_page);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Page reference string
    int page_count = sizeof(pages) / sizeof(pages[0]);
    lruPageReplacement(pages, page_count);
    return 0;
}
