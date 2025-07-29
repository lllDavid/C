#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, right, key);
    else
        return binarySearchRecursive(arr, left, mid - 1, key);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int resultIter = binarySearch(arr, size, target);
    if (resultIter != -1)
        printf("Iterative: Found at index %d\n", resultIter);
    else
        printf("Iterative: Not found\n");

    int resultRec = binarySearchRecursive(arr, 0, size - 1, target);
    if (resultRec != -1)
        printf("Recursive: Found at index %d\n", resultRec);
    else
        printf("Recursive: Not found\n");

    return 0;
}