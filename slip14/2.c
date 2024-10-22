// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n =3 as
// the number of memory frames.
// Reference String : 0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1
// Implement FIFO 

#include <stdio.h>
#include <stdbool.h>

int main() {
    int frames = 3; // Number of memory frames
    int ref_str[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1}; // Reference string
    int n = sizeof(ref_str) / sizeof(ref_str[0]); // Number of pages in the reference string

    int memory[frames]; // Memory frames
    int page_faults = 0, next_to_replace = 0;
    bool isPageFound;

    // Initialize memory frames to -1
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ref_str[i]);
    }
    printf("\n\nPage Scheduling (FIFO):\n");

    // FIFO Page Replacement Algorithm
    for (int i = 0; i < n; i++) {
        isPageFound = false;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == ref_str[i]) {
                isPageFound = true;
                break;
            }
        }

        // Page fault occurs if the page is not found
        if (!isPageFound) {
            memory[next_to_replace] = ref_str[i]; // Replace the next page
            next_to_replace = (next_to_replace + 1) % frames; // FIFO rotation
            page_faults++;

            // Print current memory frames status
            printf("After inserting %d: ", ref_str[i]);
            for (int j = 0; j < frames; j++) {
                if (memory[j] != -1)
                    printf("%d ", memory[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    // Output the total number of page faults
    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
