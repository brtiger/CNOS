#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{
int block; 
struct Node *next; 
};
int main() 
{
int n, size, i; 
int free_blocks[100]; 
for(i=0;i<100;i++) 
free_blocks[i]=0; 
printf("Enter number of files: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter size of file %d: ", i+1);
scanf("%d",&size);
struct Node *head=NULL, *temp, *newnode;
int j, count=0;
for(j=0;j<100 && count<size;j++)
{
if(free_blocks[j]==0)
{
newnode=(struct Node*)malloc(sizeof(struct Node)); 
newnode->block=j; 
newnode->next=NULL; 
if(head==NULL)
head=temp=newnode; 
else { 
temp->next=newnode; 
temp=newnode; 
}
free_blocks[j]=1; 
count++;
}
}
printf("File %d allocated blocks: ", i+1);
temp=head;
while(temp!=NULL)
{
printf("%d ", temp->block); 
temp=temp->next; 
}
printf("\n");
}
return 0;
}
