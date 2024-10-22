// Q.2 Write the simulation program to implement demand paging and show the page
// scheduling and total number of page faults for the following given page reference string.
// Give input n as the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>

int find_farthest(int pages[], int frames[], int current_index, int n, int frame_count) {
    int farthest = -1, index = -1;
    for (int i = 0; i < frame_count; i++) {
        int j;
        for (j = current_index + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) {
            return i; // If page won't be used again, replace it
        }
    }
    return (index == -1) ? 0 : index;
}

int is_in_frames(int frames[], int frame_count, int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void print_frames(int frames[], int frame_count) {
    printf("[");
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("Empty ");
    }
    printf("]\n");
}

int main() {
    int n = 16; // Number of pages in reference string
    int reference_string[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int frame_count;

    printf("Enter the number of memory frames: ");
    scanf("%d", &frame_count);

    int frames[frame_count];
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1; // Initialize frames as empty
    }

    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        int page = reference_string[i];
        if (!is_in_frames(frames, frame_count, page)) {
            int replace_index = find_farthest(reference_string, frames, i, n, frame_count);
            frames[replace_index] = page;
            page_faults++;
            printf("Page fault for %d: ", page);
            print_frames(frames, frame_count);
        } else {
            printf("Page %d already in frames: ", page);
            print_frames(frames, frame_count);
        }
    }

    printf("Total number of page faults: %d\n", page_faults);
    return 0;
}
