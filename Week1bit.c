#include <stdio.h>

int main()
{
    int data[20], stuffed[30];
    int n, i, j = 0, count = 0;

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the bits (0 or 1):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &data[i]);

    for(i = 0; i < n; i++)
    {
        stuffed[j] = data[i];

        if(data[i] == 1)
        {
            count++;
            j++;

            if(count == 5)
            {
                stuffed[j] = 0; 
                j++;
                count = 0;
            }
        }
        else
        {
            j++;
            count = 0;
        }
    }

    printf("After Bit Stuffing:\n");
    for(i = 0; i < j; i++)
        printf("%d", stuffed[i]);

    return 0;
}
