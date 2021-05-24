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

int tree_height(TreeNode *node) {
    if (node) {
        int x = tree_height(node->left);
        int y = tree_height(node->right);

        if (x > y) {
            return x + 1;
        } else {
            return y + 1;
        }
    }

    return -1;
}

TreeNode * inPre(TreeNode *node) {
    while (node && node->right) {
        node = node->right;
    }

    return node;
}

TreeNode * inSucc(TreeNode *node) {
    while (node && node->left) {
        node = node->left;
    }

    return node;
}

TreeNode * rDelete(TreeNode **node, int key) {

    TreeNode *temp; //, *temp = (*node);

    if (!(*node)) {
        return NULL;
    }

    if (!(*node)->left && !(*node)->right) {
        free((*node));
        return NULL;
    }

    if (key > (*node)->data) {
        (*node)->right = rDelete(&(*node)->right, key);

    } else if (key < (*node)->data) {
        (*node)->left = rDelete(&(*node)->left, key);

    } else {
        if (tree_height((*node)->left) > tree_height((*node)->right)) {
            temp = inPre((*node)->left);
            (*node)->data = temp->data;
            (*node)->left = rDelete(&(*node)->left, temp->data);
        } else {
            temp = inSucc((*node)->right);
            (*node)->data = temp->data;
            (*node)->right = rDelete(&(*node)->right, temp->data);
        }
    }

    return (*node);
}

void deleteInternalNodes(TreeNode **node, int root_value) {

    if ((*node)) {

        if (((*node)->left || (*node)->right) && (*node)->data != root_value) {
            rDelete(&(*node), (*node)->data);
        }

        deleteInternalNodes(&(*node)->left, root_value);

        deleteInternalNodes(&(*node)->right, root_value);
    }

}

int main() {
    // insert level by level

    int preorder[100];
    int size;

    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &preorder[i]);
    }

    int idx = 0;

    TreeNode *root = constructBinarySearchTree(preorder, &idx, preorder[idx], INT_MIN, INT_MAX, size);

    deleteInternalNodes(&root, root->data);

    inorder(root);

    return 0;
}