#include <stdio.h>

int main() {
    int p, q;
    int a[200], b[200];
    int i = 0, j = 0;

    scanf("%d", &p);
    for (int k = 0; k < p; k++) {
        scanf("%d", &a[k]);
    }

    scanf("%d", &q);
    for (int k = 0; k < q; k++) {
        scanf("%d", &b[k]);
    }

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}

