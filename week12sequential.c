#include <stdio.h>

int main() {
    int n, start, size, i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    int allocated[100] = {0}; // 100 disk blocks initialized as free

    for(i = 0; i < n; i++) {
        printf("Enter start block and size of file %d: ", i+1);
        scanf("%d %d", &start, &size);

        // Validate input
        if(start < 0 || size <= 0 || start + size > 100) {
            printf("Invalid input for file %d. Cannot allocate.\n", i+1);
            continue;
        }

        int j, flag = 0;
        // Check if blocks are already allocated
        for(j = start; j < start + size; j++) {
            if(allocated[j] == 1) {
                printf("Block %d already allocated. Cannot allocate file %d\n", j, i+1);
                flag = 1;
                break;
            }
        }

        // Allocate if free
        if(flag == 0) {
            for(j = start; j < start + size; j++) {
                allocated[j] = 1;
            }
            printf("File %d allocated from block %d to %d\n", i+1, start, start+size-1);
        }
    }

    // Show final allocation table
    printf("\nDisk Allocation Table:\n");
    for(i = 0; i < 100; i++) {
        printf("Block %d: %s\n", i, allocated[i] ? "Allocated" : "Free");
    }

    return 0;
}
