// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int frame_count) {
    int farthest = index, result = -1;
    for (int i = 0; i < frame_count; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return result == -1 ? 0 : result;
}

void optimalPageReplacement(int pages[], int n, int frame_count) {
    int frames[frame_count], page_faults = 0;
    for (int i = 0; i < frame_count; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            page_faults++;
            int replace_index = -1;
            for (int j = 0; j < frame_count; j++) {
                if (frames[j] == -1) {
                    replace_index = j;
                    break;
                }
            }
            if (replace_index == -1) replace_index = findOptimal(pages, frames, n, i + 1, frame_count);
            frames[replace_index] = pages[i];
        }
        
        // Display current frame status
        printf("Page: %d | Frames: ", pages[i]);
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf(" - ");
        }
        printf("\n");
    }
    
    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int pages[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame_count;
    
    printf("Enter number of memory frames: ");
    scanf("%d", &frame_count);
    
    optimalPageReplacement(pages, n, frame_count);
    return 0;
}
