#include <stdio.h>

int merge(int arr[], int si, int mid, int ei) {
    int temp[100];   // temp array
    int i = si;      
    int j = mid+1;     
    int k = si;
    int inv_count = 0;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i+1);  // count inversions
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= ei)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = si; i <= ei; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int si, int ei) {
    int mid, inv_count = 0;

    if (ei > si) {
        mid = (si + ei) / 2;

        inv_count += mergeSort(arr, si, mid);
        inv_count += mergeSort(arr, mid + 1, ei);

        inv_count += merge(arr, si, mid, ei);
    }
    return inv_count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;

    int inv = mergeSort(arr, 0, n - 1);

    printf("Inversion Count: %d\n", inv);
    return 0;
}