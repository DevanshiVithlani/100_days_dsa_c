#include <stdio.h>

int main() {
    int n, position, x;
    int arr[100];

   
    scanf("%d", &n);

  
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    scanf("%d", &position);
    scanf("%d", &x);


    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }


    arr[position - 1] = x;

 
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

