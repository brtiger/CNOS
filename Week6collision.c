#include <stdio.h>
#include <stdlib.h>

int main() {
    int bucket_size, leak_rate, n_packets, i;
    int bucket_storage = 0;
    int incoming_packet_size;

    printf("Enter bucket capacity (bytes): ");
    scanf("%d", &bucket_size);

    printf("Enter constant output rate (leak rate in bytes/sec): ");
    scanf("%d", &leak_rate);

    printf("Enter total number of packets: ");
    scanf("%d", &n_packets);

    printf("\nTime | Incoming | Accepted | Dropped | Bucket Status\n");
    printf("-----------------------------------------------------\n");

    for (i = 1; i <= n_packets; i++) {
        printf("Enter size of packet %d: ", i);
        scanf("%d", &incoming_packet_size);

        int accepted = 0, dropped = 0;

        // Check if packet fits in bucket
        if (incoming_packet_size <= (bucket_size - bucket_storage)) {
            bucket_storage += incoming_packet_size;
            accepted = incoming_packet_size;
            dropped = 0;
        } else {
            accepted = bucket_size - bucket_storage;
            if (accepted < 0) accepted = 0;

            dropped = incoming_packet_size - accepted;
            bucket_storage = bucket_size; // overflow
        }

        printf("%4d | %8d | %8d | %7d | %d/%d\n",
               i, incoming_packet_size, accepted, dropped,
               bucket_storage, bucket_size);

        // Leak process
        if (bucket_storage >= leak_rate) {
            bucket_storage -= leak_rate;
        } else {
            bucket_storage = 0;
        }

        printf("After leak: Bucket contains %d bytes\n\n", bucket_storage);
    }

    return 0;
}
