#include <stdio.h>
#define MAX 100

int firstOcc(int arr[], int n, int x) {
    int low = 0, high = n-1, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            ans = mid;
            high = mid - 1;  // move left
        } 
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int lastOcc(int arr[], int n, int x) {
    int low = 0, high = n-1, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            ans = mid;
            low = mid + 1;   // move right
        } 
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
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

    int first = firstOcc(arr, n, x);
    int last = lastOcc(arr, n, x);

    if (first == -1)
        printf("Count = 0\n");
    else
        printf("Count = %d\n", last - first + 1);

    return 0;
}