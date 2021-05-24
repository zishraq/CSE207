#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
} TreeNode;

typedef struct Queue {
    int size;
    int front;
    int rear;
    TreeNode **Q;
} Queue;

void queue_create(Queue *q, int size) {
    q->size = size;
    q->Q = (TreeNode **) malloc(q->size * sizeof(TreeNode *));
    q->front = q->rear = -1;
}

void enqueue(Queue *q, TreeNode * x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

TreeNode * dequeue(Queue *q) {
    TreeNode *x = NULL;

    if (q->rear == q->front) {
        printf("Queue is empty\n");
    } else {
        q->front = (q->front + 1) %q->size;
        x = q->Q[q->front];
    }

    return x;
}

int isQueueEmpty(Queue *q) {
    return q->rear == q->front;
}

void tree_create(TreeNode **node, int arr[], int size) {
    TreeNode *current, *temp;
    int i = 0;
    Queue *queue_tree = (Queue *) malloc(sizeof(Queue));

    queue_create(queue_tree, 100);

    (*node) = (TreeNode *) malloc(sizeof(TreeNode *));
    (*node)->left = (*node)->right =  NULL;

    (*node)->data = arr[i];

    enqueue(queue_tree, (*node));

    i++;
    while (!isQueueEmpty(queue_tree) && i < size) {
        current = dequeue(queue_tree);

        temp = (TreeNode *) malloc(sizeof(TreeNode *));
        temp->left = temp->right =  NULL;

        temp->data = arr[i];

        current->left = temp;

        enqueue(queue_tree, temp);

        i++;

        if (i >= size) {
            break;
        }

        temp = (TreeNode *) malloc(sizeof(TreeNode *));
        temp->left = temp->right =  NULL;

        temp->data = arr[i];

        current->right = temp;

        enqueue(queue_tree, temp);

        i++;
    }

}

void pre(TreeNode *root) {
    if (root) {
        printf("%d, ", root->data);
        pre(root->left);
        pre(root->right);
    }
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

int isBST(TreeNode * root) {
    if (root == NULL)
        return 1;

    if (root->left != NULL && root->left->data > root->data)
        return 0;

    if (root->right != NULL && root->right->data < root->data)
        return 0;

    if (!isBST(root->left) || !isBST(root->right))
        return 0;

    return 1;
}

int main() {

    int arr[100];
    int size;

    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    TreeNode *root = NULL;

    tree_create(&root, arr, size);

    if (isBST(root)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}