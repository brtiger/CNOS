#include <stdio.h> 
int main() 
{
int n; 
int bt[10]; 
int wt[10]; 
int tat[10]; 
int i; 
printf("Enter number of processes: ");
scanf("%d", &n); 
printf("Enter burst time of each process:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &bt[i]); 
}
wt[0] = 0; 
for(i = 1; i < n; i++)
{
wt[i] = wt[i-1] + bt[i-1];
}
for(i = 0; i < n; i++)
{
tat[i] = wt[i] + bt[i];
}
printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
for(i = 0; i < n; i++)
{
printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}
return 0; 
}
