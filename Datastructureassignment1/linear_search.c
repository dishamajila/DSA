#include <stdio.h>

int main()
{
    int arr[] = {101, 20, 40, 385, 210, 620, 85, 921, 12, 206};
    int n = 10;
    int key, i, found = 0;

    printf("Enter access number to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            printf("Access number found at position %d\n", i + 1);
            break;
        }
    }

    if(found == 0)
    {
        printf("Access number not found.\n");
    }

    return 0;
}