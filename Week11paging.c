#include <stdio.h>
int main() {
int page_table[20];
int pages, i;
int page_no, offset;
int frame_no, physical_address;
int page_size;
printf("Enter number of pages: ");
scanf("%d", &pages);
if(pages <= 0 || pages > 20) {
printf("Invalid number of pages\n");
return 0;
}
for(i = 0; i < pages; i++) {
printf("Enter frame number for page %d: ", i);
scanf("%d", &page_table[i]);
}
printf("Enter page size: ");
scanf("%d", &page_size);
printf("Enter page number: ");
scanf("%d", &page_no);
printf("Enter offset: ");
scanf("%d", &offset);
if(page_no < 0 || page_no >= pages) {
printf("Invalid Page Number\n");
}
else if(offset < 0 || offset >= page_size) {
printf("Invalid Offset\n");
}
else {
frame_no = page_table[page_no];
physical_address = (frame_no * page_size) + offset;
printf("Physical Address = %d\n", physical_address);
}
return 0;
}
