#include <stdio.h>
#define MAX 100

int binarySearch(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, high, x);
}

int main() {
    int n, arr[MAX], x;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}