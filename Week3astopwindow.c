#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int total_frames = 5;
    int timeout_sec = 3;
    float error_prob = 0.3;

    srand(time(NULL));

    int sent = 0;
    int frame_num = 1;
    int total_transmissions = 0;

    printf("Stop-and-Wait ARQ Simulation\n");
    printf("Frames: %d | Timeout: %d sec | Error Prob: %.2f%%\n\n",
           total_frames, timeout_sec, error_prob * 100);

    while (sent < total_frames) {
        printf("Sending frame %d\n", frame_num);
        total_transmissions++;

        usleep(500000);  // simulate delay

        float rand_val = (float)rand() / RAND_MAX;

        if (rand_val < error_prob) {
            printf(" -> Timeout after %d sec (lost ACK), retransmitting...\n",
                   timeout_sec);
            sleep(timeout_sec);
        } else {
            printf(" -> ACK for frame %d received\n", frame_num);
            sent++;
            frame_num++;
        }
    }

    printf("\nSimulation Complete!\n");
    printf("Total frames delivered: %d\n", total_frames);
    printf("Total transmissions: %d\n", total_transmissions);
    printf("Efficiency: %.2f%%\n",
           (float)total_frames * 100 / total_transmissions);

    return 0;
}
