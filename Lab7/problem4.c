#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
} TreeNode;

TreeNode * treeCreate(TreeNode *root, int *arr, int i, int size) {
    if (i < size) {
        TreeNode *temp = (TreeNode *) malloc(sizeof(TreeNode));
        temp->data = arr[i];
        temp->left = temp->right = NULL;

        root = temp;

        root->left = treeCreate(root->left, arr, 2 * i + 1, size);

        root->right = treeCreate(root->right, arr, 2 * i + 2, size);
    }
    return root;
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

    printf("Enter size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    TreeNode *root = treeCreate(root, arr, 0, size);

    if (isBST(root)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}
