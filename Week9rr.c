#include <stdio.h>
int main()
{
int n, tq; 
int bt[10]; 
int rem[10]; 
int wt[10]; 
int tat[10];
int i, time = 0, done; 
printf("Enter number of processes: ");
scanf("%d", &n); 
printf("Enter burst times:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &bt[i]); 
rem[i] = bt[i]; 

wt[i] = 0; 
}
printf("Enter time quantum: ");
scanf("%d", &tq); 
do
{
done = 1; 
for(i = 0; i < n; i++)
{
if(rem[i] > 0) 
{
done = 0;
if(rem[i] > tq)
{
time += tq; 
rem[i] -= tq; 
}
else
{
time += rem[i]; 
wt[i] = time - bt[i]; 
rem[i] = 0; 
}
}
}
}
while(!done); 
for(i = 0; i < n; i++)
{
tat[i] = wt[i] + bt[i]; 
}
printf("\nBurst Waiting Turnaround\n");
for(i = 0; i < n; i++)
{
printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);
}
return 0; 
}
