#include <stdio.h>
#include <limits.h>
#define MAX 100

double findMedian(int A[], int B[], int n) {
    int low = 0, high = n;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = n - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : A[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : B[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : A[cut1];
        int r2 = (cut2 == n) ? INT_MAX : B[cut2];

        if (l1 <= r2 && l2 <= r1) {
            return ( (l1 > l2 ? l1 : l2) + 
                     (r1 < r2 ? r1 : r2) ) / 2.0;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}

int main() {
    int n, A[MAX], B[MAX];

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter array A:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter array B:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    printf("Median = %.2lf\n", findMedian(A, B, n));

    return 0;
}