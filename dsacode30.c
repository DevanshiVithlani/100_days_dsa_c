#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insert(struct Node* head, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printPoly(struct Node* head) {
    struct Node* temp = head;
    int first = 1;

    while(temp != NULL) {
        if(temp->coeff != 0) {
            if(!first)
                printf(" + ");

            if(temp->exp > 1)
                printf("%dx^%d", temp->coeff, temp->exp);
            else if(temp->exp == 1)
                printf("%dx", temp->coeff);
            else
                printf("%d", temp->coeff);

            first = 0;
        }
        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    printPoly(head);

    return 0;
}
