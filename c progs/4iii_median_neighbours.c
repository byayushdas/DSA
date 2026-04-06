#include <stdio.h>

// Partition function
int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i = si;

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            // inline swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // place pivot at correct position
    int temp = arr[i];
    arr[i] = arr[ei];
    arr[ei] = temp;

    return i;
}

// QuickSelect
int quickSelect(int arr[], int si, int ei, int k) {
    if (si <= ei) {
        int pi = partition(arr, si, ei);

        if (pi == k)
            return arr[pi];
        else if (pi > k)
            return quickSelect(arr, si, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, ei, k);
    }
    return -1;
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = 8;

    int k = n / 2;

    int median = quickSelect(arr, 0, n - 1, k);
    int left = quickSelect(arr, 0, n - 1, k - 1);
    int right = quickSelect(arr, 0, n - 1, k + 1);

    printf("Median: %d\n", median);
    printf("Neighbors: %d and %d\n", left, right);

    return 0;
}