#include <stdio.h>
#include <string.h>

#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    dq[front] = x;
}

void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

int pop_front() {
    if (isEmpty()) return -1;

    int val = dq[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    return val;
}

int pop_back() {
    if (isEmpty()) return -1;

    int val = dq[rear];

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    return val;
}

int getFront() {
    if (isEmpty()) return -1;
    return dq[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return dq[rear];
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } 
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } 
        else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        } 
        else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        } 
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        } 
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        } 
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } 
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
    }

    display();
    return 0;
}
