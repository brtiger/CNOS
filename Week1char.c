#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], c[200];   
    int i, k = 0, n;

    printf("Enter the data: ");
    fgets(a, sizeof(a), stdin);

    n = strlen(a);
    if (a[n-1] == '\n')
        a[n-1] = '\0';

    n = strlen(a);

    for (i = 0; i < n; i++)
    {
        
        if (i + 2 < n)
        {
            if ((a[i] == 'd' && a[i+1] == 'l' && a[i+2] == 'e') ||
                (a[i] == 'e' && a[i+1] == 's' && a[i+2] == 'c'))
            {
                c[k++] = 'e';
                c[k++] = 's';
                c[k++] = 'c';
            }
        }

        c[k++] = a[i];
    }

    c[k] = '\0'; 

    printf("DLESTX");   
    printf("%s", c);   
    printf("DLEETX");   
    return 0;
}
