//write a program to take input marks of ten student randomly in an array
//sort the array using merge sort and show the highest and lowest marks
//input:size of array=10
//array items=[80,73,59,92,86,47,92,58,91,48]

#include <stdio.h>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main()
{
    int marks[10];
    int i;

    printf("Enter marks of 10 students:\n");

    // Input marks
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &marks[i]);
    }

    // Sort the array
    mergeSort(marks, 0, 9);

    // Display sorted array
    printf("\nSorted Marks:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", marks[i]);
    }

    // Display lowest and highest marks
    printf("\n\nLowest Marks = %d\n", marks[0]);
    printf("Highest Marks = %d\n", marks[9]);

    return 0;
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    int i, j, k;

    // Copy data to temporary arrays
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Merge the temporary arrays
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}