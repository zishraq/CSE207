#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void create_node(Node *node, int n);

void display(Node *node);

void reverse_list(Node **node);

int main() {
    int n;

    head = (Node *) malloc(sizeof(Node));

    printf("Input the number of nodes: ");
    scanf(" %d", &n);

    create_node(head, n);

    printf("Data entered in the list are: \n");
    display(head);

    reverse_list(&head);

    printf("The list in reverse are : \n");
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

void reverse_list(Node **node) {
    Node *current_node = NULL, *prev_node = NULL;

    while ((*node) != NULL) {
        prev_node = current_node;
        current_node = (*node);
        (*node) = (*node)->next;
        current_node->next = prev_node;
    }

    (*node) = current_node;
}

void display(Node *node) {
    while (node != NULL) {
        printf("Data = %d\n", node->data);
        node = node->next;
    }
}
