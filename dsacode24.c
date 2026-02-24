#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* deleteFirst(struct Node* head, int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);

    return head;
}


void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, key, i;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newnode;

    for (i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    scanf("%d", &key);

    head = deleteFirst(head, key);

    display(head);

    return 0;
}
