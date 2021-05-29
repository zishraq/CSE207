#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    struct TreeNode *left;
    int data;
    int height;
    struct TreeNode *right;
} TreeNode;

int nodeHeight(TreeNode *node) {
    int height_left, height_right;

    height_left = node && node->left ? node->left->height : 0;
    height_right = node && node->right ? node->right->height : 0;

    return height_left > height_right ? height_left + 1 : height_right + 1;
}

int balanceFactor(TreeNode *node) {
    int height_left, height_right;

    height_left = node && node->left ? node->left->height : 0;
    height_right = node && node->right ? node->right->height : 0;

    return height_left - height_right;
}

TreeNode * LLRotation(TreeNode *node) {
    TreeNode *node_left = node->left;
    TreeNode *node_left_right = node_left->right;

    node_left->right = node;
    node->left = node_left_right;

    node->height = nodeHeight(node);
    node_left->height = nodeHeight(node_left);

    return node_left;
}

TreeNode * RRRotation(TreeNode *node) {
    TreeNode *node_right = node->right;
    TreeNode *node_right_left = node_right->left;

    node_right->left = node;
    node->right = node_right_left;

    node->height = nodeHeight(node);
    node_right->height = nodeHeight(node_right);

    return node_right;
}

TreeNode * LRRotation(TreeNode *node) {
    TreeNode *node_left = node->left;
    TreeNode *node_left_right = node_left->right;

    node_left->right = node_left_right->left;
    node->left = node_left_right->right;

    node_left_right->right = node;
    node_left_right->left = node_left;

    node_left->height = nodeHeight(node_left);
    node->height = nodeHeight(node);
    node_left_right->height = nodeHeight(node_left_right);

    return node_left_right;
}

TreeNode * RLRotation(TreeNode *node) {
    TreeNode *node_right = node->right;
    TreeNode *node_right_left = node_right->left;

    node_right->left = node_right_left->right;
    node->right = node_right_left->left;

    node_right_left->right = node_right;
    node_right_left->left = node;

    node_right->height = nodeHeight(node_right);
    node->height = nodeHeight(node);
    node_right_left->height = nodeHeight(node_right_left);

    return node_right_left;
}

TreeNode * insert(TreeNode *node, int value) {
    TreeNode *new_node;

    if (!node) {
        new_node = (TreeNode *) malloc(sizeof(TreeNode));
        new_node->data = value;
        new_node->height = 1;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if (value > node->data) {
        node->right = insert(node->right, value);
    } else if (value < node->data) {
        node->left = insert(node->left, value);
    }

    node->height = nodeHeight(node);

    if (balanceFactor(node) == 2 && balanceFactor(node->left) == 1) {
        return LLRotation(node);

    } else if (balanceFactor(node) == 2 && balanceFactor(node->left) == -1) {
        return LRRotation(node);

    } else if (balanceFactor(node) == -2 && balanceFactor(node->right) == -1) {
        return RRRotation(node);

    } else if (balanceFactor(node) == -2 && balanceFactor(node->right) == 1) {
        return RLRotation(node);

    }

    return node;
}

void inorder(TreeNode *node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    TreeNode *root = NULL;

    int n, node;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter a node: ");
        scanf("%d", &node);
        root = insert(root, node);
    }

    inorder(root);

    return 0;
}
