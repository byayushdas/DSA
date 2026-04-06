#include <stdio.h>
#define MAX 100

int main() {
    int n, arr[MAX], x;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &x);

    int i = 0, j = n - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == x) {
            printf("Pair found: %d + %d = %d\n", arr[i], arr[j], x);
            return 0;
        }
        else if (sum < x)
            i++;
        else
            j--;
    }

    printf("No pair found\n");
    return 0;
}