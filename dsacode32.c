#include <stdio.h>

int main() {
    int n, m, i, top = -1;

    scanf("%d", &n);

    int stack[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    scanf("%d", &m);

    // Perform m pop operations
    for(i = 0; i < m && top >= 0; i++) {
        top--;
    }

    // Print stack from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if(i != 0) printf(" ");
    }

    return 0;
}
