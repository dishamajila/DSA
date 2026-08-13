//Write a program to take input in an array 10 unordered number
// apply quick sort to order the array in ascending order
//input:array size=10
//array items=[8,2,10,6,5,12,18,9,4,11]

#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[10];
    int i;

    printf("Enter 10 numbers:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, 9);

    printf("Sorted array in ascending order:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for(j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}