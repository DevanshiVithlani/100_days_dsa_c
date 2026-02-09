#include <stdio.h>

int main() {
    char s[100];
    int i;

    scanf("%s", s);

    for (i = 99; i >= 0; i--) {
        if (s[i] != '\0')
            printf("%c", s[i]);
    }

    return 0;
}

