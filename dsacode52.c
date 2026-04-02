#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order construction
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// LCA function
struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->val == p || root->val == q)
        return root;

    struct TreeNode* left = LCA(root->left, p, q);
    struct TreeNode* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* root = buildTree(arr, n);

    struct TreeNode* ans = LCA(root, p, q);

    if (ans)
        printf("%d\n", ans->val);

    return 0;
}
