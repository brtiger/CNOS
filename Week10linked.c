#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt; 
struct Node 
{
int block; 
struct Node *next; 
};
int main() 
{
int n, size, i; 
int free_blocks[100];
for(i=0;i&lt;100;i++) free_blocks[i]=0; 
printf(&quot;Enter number of files: &quot;);
scanf(&quot;%d&quot;,&amp;n);
for(i=0;i&lt;n;i++)
{
printf(&quot;Enter size of file %d: &quot;, i+1);
scanf(&quot;%d&quot;,&amp;size);
struct Node *head=NULL, *temp, *newnode;
int j, count=0;
for(j=0;j&lt;100 &amp;&amp; count&lt;size;j++)
{
if(free_blocks[j]==0) 
{

newnode=(struct Node*)malloc(sizeof(struct Node)); 
newnode-&gt;block=j; 
newnode-&gt;next=NULL; 
if(head==NULL) head=temp=newnode; 
else { temp-&gt;next=newnode; temp=newnode; } 
free_blocks[j]=1; 
count++;
}
}
printf(&quot;File %d allocated blocks: &quot;, i+1);
temp=head;
while(temp!=NULL)
{
printf(&quot;%d &quot;, temp-&gt;block); 
temp=temp-&gt;next;
}
printf(&quot;\n&quot;);
}
return 0;
}
