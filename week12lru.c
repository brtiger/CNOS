#include <stdio.h>
int main() {
int frames[10], pages[20], time[10];
int frame_count, page_count;
int i, j, pos, faults = 0;
int found, counter = 0, least;
printf("Enter number of frames: ");
scanf("%d", &frame_count);
printf("Enter number of pages: ");
scanf("%d", &page_count);
printf("Enter page reference string:\n");
for(i = 0; i < page_count; i++)
scanf("%d", &pages[i]);
for(i = 0; i < frame_count; i++) {
frames[i] = -1;
time[i] = 0;
}
for(i = 0; i < page_count; i++) {
found = 0;
counter++;
for(j = 0; j < frame_count; j++) {
if(frames[j] == pages[i]) {
time[j] = counter; // Update recent use time
found = 1;
break;
}
}
// If page fault occurs
if(found == 0) {
least = 0;
for(j = 1; j < frame_count; j++) {
if(time[j] < time[least])
least = j;
}
frames[least] = pages[i];
time[least] = counter;
faults++;
}
printf("Total Page Faults = %d\n", faults);
return 0;
}
