#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        if (i < n) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

// Check if Complete Binary Tree
int isComplete(struct Node* root) {
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int foundNull = 0;

    while (front < rear) {
        struct Node* curr = queue[front++];

        if (curr == NULL) {
            foundNull = 1;
        } else {
            if (foundNull)
                return 0;

            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }
    return 1;
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    if (!root) return 1;

    // Leaf node
    if (!root->left && !root->right)
        return 1;

    // Only left child
    if (!root->right)
        return (root->data <= root->left->data) && isMinHeap(root->left);

    // Both children
    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isComplete(root) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
