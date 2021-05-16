#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void create_node(Node *node, int n);

void delete_any_middle_node(Node **node, int position);

void delete_any_middle_node_test(Node *node, int position);

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

    printf("Input the position of node to delete: ");
    scanf(" %d", &position);

    delete_any_middle_node(&head, position);

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

void delete_any_middle_node(Node **node, int position)  {
    Node *delete_node = (*node), *prev_node = NULL;

    if ((*node) != NULL) {
        if (position >= 1 || position <= count((*node))) {
            if (position == 1) {
                (*node) = (*node)->next;
                free(delete_node);
            } else {
                for (int i = 0; i < position - 1; i++) {
                    prev_node = delete_node;
                    delete_node = delete_node->next;
                }

                prev_node->next = delete_node->next;
                free(delete_node);
            }
        }
    }
}

void delete_any_middle_node_test(Node *node, int position)  {
    Node *delete_node = node, *prev_node = NULL;

    if (node != NULL) {
        if (position >= 1 || position <= count(node)) {
            if (position == 1) {
                node = node->next;
                free(delete_node);
            } else {
                for (int i = 0; i < position - 1; i++) {
                    prev_node = delete_node;
                    delete_node = delete_node->next;
                }

                prev_node->next = delete_node->next;
                free(delete_node);
            }
        }
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
