#include <stdio.h>
int main() {
int base[20], limit[20];
int segments, i;
int seg_no, offset;
int physical_address;
printf("Enter number of segments: ");
scanf("%d", &segments);
if(segments <= 0 || segments > 20) {
printf("Invalid number of segments\n");
return 0;
}
for(i = 0; i < segments; i++) {
printf("Enter base address for segment %d: ", i);
scanf("%d", &base[i]);
printf("Enter limit for segment %d: ", i);
scanf("%d", &limit[i]);
}
printf("Enter segment number: ");
scanf("%d", &seg_no);
printf("Enter offset: ");
scanf("%d", &offset);
if(seg_no < 0 || seg_no >= segments) {
printf("Invalid Segment Number\n");
}
else if(offset < 0 || offset >= limit[seg_no]) {
printf("Error: Offset exceeds segment limit\n");
}

else {
physical_address = base[seg_no] + offset;
printf("Physical Address = %d\n", physical_address);
}
return 0;
}
