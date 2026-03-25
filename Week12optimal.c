#include <stdio.h>
int main() {
int frames[10], pages[20];
int frame_count, page_count;
int i, j, k, faults = 0;
int found, farthest, index;
// Read number of frames
printf("Enter number of frames: ");
scanf("%d", &frame_count);
// Read number of pages
printf("Enter number of pages: ");
scanf("%d", &page_count);
// Read page reference string
printf("Enter page reference string:\n");
for(i = 0; i < page_count; i++)
scanf("%d", &pages[i]);
// Initialize frames
for(i = 0; i < frame_count; i++)
frames[i] = -1;
// Process each page
for(i = 0; i < page_count; i++) {
found = 0;
// Check if page already exists
for(j = 0; j < frame_count; j++) {

if(frames[j] == pages[i]) {
found = 1;
break;
}
}
// If page fault occurs
if(found == 0) {
faults++;
farthest = i + 1;
index = -1;
// Find page used farthest in future
for(j = 0; j < frame_count; j++) {
for(k = i + 1; k < page_count; k++) {
if(frames[j] == pages[k])
break;
}
// Page not used again
if(k == page_count) {
index = j;
break;
}
// Track farthest future use
if(k > farthest) {
farthest = k;
index = j;
}
}
// Replace selected page
if(index == -1)
frames[0] = pages[i];
else
frames[index] = pages[i];
}
}
// Display total page faults
printf("Total Page Faults = %d\n", faults);
return 0;
}
