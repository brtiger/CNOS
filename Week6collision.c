#include<stdio.h>
#include<stdlib.h>
int main(){
    int bucket_size,leak_rate,n_packets,i;
    int bucket_storage=0;
    int incoming_packet_size;
    printf("Enter bucket capacity(bytes): ");
    scanf("%d",&bucket_size);
    printf("Enter constant output rate (leak rate in bytes/sec): ");
    scanf("%d",&leak_rate);
    printf("Enter total number of packtes to simulate: ");
    scanf("%d",&n_packets);
    printf("\nTime | Incoming | Accepted | Dropped | Current Bucket Status\n");
    printf("--------------------------------------------------------\n");
    for(i=1;i<=n_packets;i++){
        printf("Enter size of packet %d: ",i);
        scanf("%d",&incoming_packet_size);
        if(incoming_packet_size <= (bucket_size-bucket_storage)){
            bucket_storage+=incoming_packet_size;
            printf("%2d | %8d | %8d | %7d | %d/%d\n",i,incoming_packet_size,incoming_packet_size,0,bucket_storage,bucket_size);
            
        
        }
        else{
            int dropped=incoming_packet_size-(bucket_size-bucket_storage);
            int accepted = incoming_packet_size-dropped;
            bucket_storage=bucket_size;
            printf("%2d | %8d | %8d | %7d | %d/%d (OVERFLOW!)\n",i,incoming_packet_size,accepted,dropped,bucket_storage,bucket_size);
            
        }
        if(bucket_storage>=leak_rate){
            bucket_storage-=leak_rate;
            
        }else{
            bucket_storage=0;
        }
        printf("After Leak: Bucket contains %d bytes\n\n",bucket_storage);
    }
    return 0;
}
