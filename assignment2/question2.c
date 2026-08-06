#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int marks[10];

    printf("Enter marks of 10 students:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &marks[i]);
    }

    printf("Unsorted marks: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");

    mergeSort(marks, 0, 9);

    printf("Sorted marks: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");

    printf("Highest mark: %d\n", marks[9]);
    printf("Lowest mark: %d\n", marks[0]);

    return 0;
}

