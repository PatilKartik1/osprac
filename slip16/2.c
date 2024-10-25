// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n =3 as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>

#define MAX 100

// Function to check if a page is already present in memory
int isPagePresent(int memory[], int frames, int page) {
    for (int i = 0; i < frames; i++) {
        if (memory[i] == page)
            return 1;
    }
    return 0;
}

// Function to find the optimal page to replace
int findOptimalPage(int memory[], int frames, int ref_str[], int ref_size, int current) {
    int farthest = current, pos = -1;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = current; j < ref_size; j++) {
            if (memory[i] == ref_str[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == ref_size) // If a page is not used again in the future
            return i;
    }
    return pos == -1 ? 0 : pos;
}

int main() {
    int frames = 3;
    int ref_str[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int ref_size = sizeof(ref_str) / sizeof(ref_str[0]);

    int memory[MAX], page_faults = 0;
    for (int i = 0; i < frames; i++) 
        memory[i] = -1;

    printf("Page Reference String: ");
    for (int i = 0; i < ref_size; i++) 
        printf("%d ", ref_str[i]);
    printf("\n\nPage Scheduling:\n");

    for (int i = 0; i < ref_size; i++) {
        if (!isPagePresent(memory, frames, ref_str[i])) {
            int replace_idx = findOptimalPage(memory, frames, ref_str, ref_size, i + 1);
            memory[replace_idx] = ref_str[i];
            page_faults++;

            // Display current memory state
            printf("Step %2d: ", i + 1);
            for (int j = 0; j < frames; j++) {
                if (memory[j] != -1) 
                    printf("%d ", memory[j]);
                else 
                    printf("- ");
            }
            printf("(Page Fault)\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
