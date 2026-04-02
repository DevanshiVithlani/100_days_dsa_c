#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for tree building
struct QueueNode {
    struct Node* treeNode;
    int hd;
};

struct Queue {
    struct QueueNode arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].treeNode = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QueueNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Map using array (HD range: -1000 to +1000)
    int offset = 1000;
    int result[2001][100]; // storing nodes
    int count[2001] = {0};

    struct Queue q;
    q.front = q.rear = 0;

    enqueue(&q, root, 0);

    int minHD = 0, maxHD = 0;

    while (q.front < q.rear) {
        struct QueueNode temp = dequeue(&q);
        struct Node* node = temp.treeNode;
        int hd = temp.hd;

        int index = hd + offset;

        result[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            enqueue(&q, node->left, hd - 1);

        if (node->right)
            enqueue(&q, node->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", result[idx][j]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
