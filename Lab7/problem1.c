#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode * constructBinarySearchTree(int preorder[], int *idx, int value, int MIN, int MAX, int SIZE) {
    if (*idx > SIZE) {
        return NULL;
    }

    TreeNode *root = NULL;

    if (value > MIN && value < MAX) {
        root = (TreeNode *) malloc(sizeof(TreeNode));

        root->data = value;
        root->left = root->right = NULL;

        *idx = *idx + 1;

        if (*idx < SIZE) {
            root->left = constructBinarySearchTree(preorder, idx, preorder[*idx], MIN, value, SIZE);
        }

        if (*idx < SIZE) {
            root->right = constructBinarySearchTree(preorder, idx, preorder[*idx], value, MAX, SIZE);
        }

    }

    return root;
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

int main() {
    int preorder[100];
    int size;

    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &preorder[i]);
    }

    int idx = 0;

    TreeNode *root = constructBinarySearchTree(preorder, &idx, preorder[idx], INT_MIN, INT_MAX, size);

    inorder(root);

    return 0;
}