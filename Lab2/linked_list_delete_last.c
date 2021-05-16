#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void create_node(Node *node, int n);

void delete_last_node(Node **node);

void display(Node *node);

int main() {
    int n;

    head = (Node *) malloc(sizeof(Node));

    printf("Input the number of nodes: ");
    scanf(" %d", &n);

    create_node(head, n);

    printf("Data entered in the list are: \n");
    display(head);

    delete_last_node(&head);

    printf("The new list after deletion the last node are: \n");
    display(head);

    return 0;
}

void create_node(Node *node, int n) {
    Node *tail, *temp;

    int data;

    printf("Input data for node 1: ");
    scanf(" %d", &data);

    node->data = data;
    node->next = NULL;
    tail = node;

    for (int i = 2; i <= n; i++) {
        printf("Input data for node %d: ", i);
        scanf(" %d", &data);

        temp = (Node *) malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;

        tail->next = temp;
        tail = temp;
    }
}

void delete_last_node(Node **node) {
    Node *delete_node, *pre_node;

    if ((*node) != NULL) {
        delete_node = (*node);
        pre_node = (*node);

        while (delete_node->next != NULL) {
            pre_node = delete_node;
            delete_node = delete_node->next;
        }

        if (delete_node == (*node)) {
            (*node) = NULL;
        } else {
            pre_node->next = NULL;
        }

        free(delete_node);
    }
}

void display(Node *node) {
    while (node != NULL) {
        printf("Data = %d\n", node->data);
        node = node->next;
    }
}
