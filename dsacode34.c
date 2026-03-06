#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        } else {
            int b = pop(&stack);
            int a = pop(&stack);

            if (token[0] == '+') push(&stack, a + b);
            else if (token[0] == '-') push(&stack, a - b);
            else if (token[0] == '*') push(&stack, a * b);
            else if (token[0] == '/') push(&stack, a / b);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    printf("%d", evaluatePostfix(expr));
    return 0;
}
