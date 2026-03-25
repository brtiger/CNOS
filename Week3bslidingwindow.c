#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int w, f, i, frames[50];
    float loss_prob = 0.2;
    int timeout_sec = 2;

    srand(time(NULL));

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    if (f > 50) {
        printf("Max 50 frames!\n");
        return 0;
    }

    printf("Enter %d frames:\n", f);
    for (i = 0; i < f; i++) {
        scanf("%d", &frames[i]);
    }

    printf("\n=== Sliding Window (Go-Back-N) with %d%% frame loss ===\n\n",
           (int)(loss_prob * 100));

    int base = 0;
    int next_seq = 0;
    int total_sent = 0;
    int retransmits = 0;

    while (base < f) {

        for (i = base; i < f && (i - base) < w; i++) {
            printf("Sending frame %d (data: %d)\n", i, frames[i]);
            total_sent++;

            if (((float)rand() / RAND_MAX) < loss_prob) {
                printf(" -> Frame %d LOST!\n", i);
                retransmits++;
                printf(" -> Retransmitting from frame %d...\n", base);
                sleep(timeout_sec);
                break;  // Go-Back-N: restart from base
            }
        }

        // If all frames in window sent successfully
        if (i == base + w || i >= f) {
            printf("ACK received up to frame %d\n\n", i - 1);
            base = i;
        }
    }

    float efficiency = ((float)f * 100.0) / total_sent;

    printf("=== Simulation Complete ===\n");
    printf("Total transmissions: %d\n", total_sent);
    printf("Retransmissions: %d\n", retransmits);
    printf("Efficiency: %.2f%%\n", efficiency);

    return 0;
}
