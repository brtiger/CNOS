#include <stdio.h> 
int main()
{
int n; 
int bt[10]; 
int pr[10]; 
int wt[10]; 
int tat[10]; 
int i, j, temp; 
printf("Enter number of processes: ");
scanf("%d", &n); 
printf("Enter burst time and priority:\n");
for(i = 0; i < n; i++)
{
scanf("%d %d", &bt[i], &pr[i]);
}
for(i = 0; i < n; i++)
{
for(j = i + 1; j < n; j++)
{
if(pr[i] > pr[j])
{
temp = pr[i]; 
pr[i] = pr[j];
pr[j] = temp;
temp = bt[i]; 
bt[i] = bt[j];
bt[j] = temp;
}
}
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
printf("\nBurst Priority Waiting Turnaround\n");
for(i = 0; i < n; i++)
{
printf("%d\t%d\t%d\t%d\n", bt[i], pr[i], wt[i], tat[i]);
}
return 0;
}
