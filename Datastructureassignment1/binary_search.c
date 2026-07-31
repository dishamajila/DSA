// An online shop keeps it products catalog sorted by product id(whole number) in acending order.
// when a costomer search for a specific product id the system return true if the product id present int he catalog else it return false.
// which searching tecnique is used to find the product id quickly from the catalog.
// implement this searching method using a function. 
// the function takse parameters product id list and size of the list and product id to be searched.
// Sample Inputs : [2,8,9,16,18,26,38,48,51,90]
// Case 1: product to be search : 26
// Case 2: product to be search : 49
#include <stdio.h>
void binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found\n");
}
int main() {
    int arr[10] = {2,8,9,16,18,26,38,48,51,90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);
    binarySearch(arr, size, target);
    return 0;
}