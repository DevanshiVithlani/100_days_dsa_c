#include <stdio.h>

int main() {
    int n, position;
    int arr[100];

   
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    scanf("%d", &position);

    
    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

