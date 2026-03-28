#include <stdio.h>

int findBitonic(int arr[], int si, int ei) {
    while (si <= ei) {
        int mid = (si + ei) / 2;

        // Check if mid is peak
        if (mid > 0 && mid < ei) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return arr[mid];
            }
            // Increasing part → move right
            else if (arr[mid] > arr[mid - 1]) {
                si = mid + 1;
            }
            // Decreasing part → move left
            else {
                ei = mid - 1;
            }
        }
        // Edge cases
        else if (mid == 0) {
            return (arr[0] > arr[1]) ? arr[0] : arr[1];
        }
        else if (mid == ei) {
            return (arr[ei] > arr[ei - 1]) ? arr[ei] : arr[ei - 1];
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = 6;

    int result = findBitonic(arr, 0, n - 1);

    printf("Bitonic Point: %d\n", result);

    return 0;
}