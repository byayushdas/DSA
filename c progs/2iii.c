#include <stdio.h>
#define MAX 100

typedef struct {
    int min, secondMin;
    int max, secondMax;
} Result;

// -------- Divide & Conquer --------
Result find(int arr[], int low, int high) {
    Result res;

    // Base case: one element
    if (low == high) {
        res.min = res.max = arr[low];
        res.secondMin = res.secondMax = -1;
        return res;
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            res.min = arr[low];
            res.secondMin = arr[high];
            res.max = arr[high];
            res.secondMax = arr[low];
        } else {
            res.min = arr[high];
            res.secondMin = arr[low];
            res.max = arr[low];
            res.secondMax = arr[high];
        }
        return res;
    }

    int mid = (low + high) / 2;

    Result left = find(arr, low, mid);
    Result right = find(arr, mid + 1, high);

    // Combine results
    res.min = (left.min < right.min) ? left.min : right.min;
    res.secondMin = (left.min < right.min) ?
        ((left.secondMin < right.min) ? left.secondMin : right.min) :
        ((right.secondMin < left.min) ? right.secondMin : left.min);

    res.max = (left.max > right.max) ? left.max : right.max;
    res.secondMax = (left.max > right.max) ?
        ((left.secondMax > right.max) ? left.secondMax : right.max) :
        ((right.secondMax > left.max) ? right.secondMax : left.max);

    return res;
}

// -------- MAIN --------
int main() {
    int n, arr[MAX];

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Result res = find(arr, 0, n - 1);

    printf("Second Smallest = %d\n", res.secondMin);
    printf("Second Largest = %d\n", res.secondMax);

    return 0;
}