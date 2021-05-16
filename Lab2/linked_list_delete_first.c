#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void create_node(Node *node, int n);

void delete_first_node(Node **node);

void delete_first_node_test(Node *node);

void display(Node *node);

int main() {
    int n;

    head = (Node *) malloc(sizeof(Node));

    printf("Input the number of nodes: ");
    scanf(" %d", &n);

    create_node(head, n);

    printf("Data entered in the list are: \n");
    display(head);

    delete_first_node(&head);
//    delete_first_node_test(head);

    printf("Data, after deletion of first node: ");
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

void delete_first_node(Node **node) {
    if (*node != NULL) {
        Node *delete_node = *node;

        printf("Data of node 1 which is being deleted is: %d\n", delete_node->data);

        *node = (*node)->next;
        free(delete_node);
    }
}

void delete_first_node_test(Node *node) {
    if (node != NULL) {
        Node *delete_node = node;

        printf("Data of node 1 which is being deleted is: %d\n", delete_node->data);

        node = node->next;
        free(delete_node);
    }
}

void display(Node *node) {
    while (node != NULL) {
        printf("Data = %d\n", node->data);
        node = node->next;
    }
}
