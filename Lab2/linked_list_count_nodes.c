#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void create_node(Node *node, int n);

void display(Node *node);

int count(Node *node);

int main() {
    int n, position;

    head = (Node *) malloc(sizeof(Node));

    printf("Input the number of nodes: ");
    scanf(" %d", &n);

    create_node(head, n);

    printf("Data entered in the list are: \n");
    display(head);

    printf("Total number of nodes = %d\n", count(head));

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

int count(Node *node) {
    int c = 0;

    while (node != NULL) {
        node = node->next;
        c++;
    }

    return c;
}

void display(Node *node) {
    while (node != NULL) {
        printf("Data = %d\n", node->data);
        node = node->next;
    }
}
