#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int length(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int intersection(struct Node* head1, struct Node* head2) {
    int l1 = length(head1);
    int l2 = length(head2);

    struct Node *p1 = head1, *p2 = head2;
    int diff = abs(l1 - l2);

    if (l1 > l2)
        while (diff--) p1 = p1->next;
    else
        while (diff--) p2 = p2->next;

    while (p1 && p2) {
        if (p1->data == p2->data)
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;
}

int main() {
    int n, m, i, x;
    struct Node *head1 = NULL, *head2 = NULL, *temp;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (!head1) {
            head1 = createNode(x);
            temp = head1;
        } else {
            temp->next = createNode(x);
            temp = temp->next;
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        if (!head2) {
            head2 = createNode(x);
            temp = head2;
        } else {
            temp->next = createNode(x);
            temp = temp->next;
        }
    }

    int ans = intersection(head1, head2);

    if (ans != -1)
        printf("%d", ans);
    else
        printf("No Intersection");

    return 0;
}
