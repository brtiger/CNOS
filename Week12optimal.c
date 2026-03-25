#include <stdio.h>
int main() {
int frames[10], pages[20];
int frame_count, page_count;
int i, j, k, faults = 0;
int found, farthest, index;
printf("Enter number of frames: ");
scanf("%d", &frame_count);
printf("Enter number of pages: ");
scanf("%d", &page_count);
printf("Enter page reference string:\n");
for(i = 0; i < page_count; i++)
scanf("%d", &pages[i]);
for(i = 0; i < frame_count; i++)
frames[i] = -1;
for(i = 0; i < page_count; i++) {
found = 0;

for(j = 0; j < frame_count; j++) {

if(frames[j] == pages[i]) {
found = 1;
break;
}
}

if(found == 0) {
faults++;
farthest = i + 1;
index = -1;

for(j = 0; j < frame_count; j++) {
for(k = i + 1; k < page_count; k++) {
if(frames[j] == pages[k])
break;
}

if(k == page_count) {
index = j;
break;
}

if(k > farthest) {
farthest = k;
index = j;
}
}

if(index == -1)
frames[0] = pages[i];
else
frames[index] = pages[i];
}
}

printf("Total Page Faults = %d\n", faults);
return 0;
}
