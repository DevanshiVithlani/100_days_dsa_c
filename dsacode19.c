#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int left = 0;
    int right = n - 1;
    int minSum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", num1, num2);

    return 0;
}

