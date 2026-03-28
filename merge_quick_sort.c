#include <stdio.h>

// ---------------- MERGE SORT ----------------
void merge(int arr[], int temp[], int si, int mid, int ei) {
    int i = si;
    int j = mid + 1;
    int k = si;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= ei)
        temp[k++] = arr[j++];

    for (int x = si; x <= ei; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int temp[], int si, int ei) {
    if (si < ei) {
        int mid = (si + ei) / 2;

        mergeSort(arr, temp, si, mid);
        mergeSort(arr, temp, mid + 1, ei);

        merge(arr, temp, si, mid, ei);
    }
}

// ---------------- QUICK SORT ----------------
int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i = si - 1;

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[ei];
    arr[ei] = temp;

    return i + 1;
}

void quickSort(int arr[], int si, int ei) {
    if (si < ei) {
        int pi = partition(arr, si, ei);

        quickSort(arr, si, pi - 1);
        quickSort(arr, pi + 1, ei);
    }
}

// ---------------- MAIN ----------------
int main() {
    int arr1[] = {5, 2, 4, 6, 1, 3};
    int arr2[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    int temp[6];

    // Merge Sort
    mergeSort(arr1, temp, 0, n - 1);

    printf("Merge Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);

    printf("\n");

    // Quick Sort
    quickSort(arr2, 0, n - 1);

    printf("Quick Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);

    return 0;
}