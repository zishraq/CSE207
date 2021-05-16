#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void enqueue(Node **front_node, Node **rear_node, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node *));

    if (new_node == NULL) {
        printf("Queue is full!\n");
    } else {
        new_node->data = value;
        new_node->next = NULL;

        if ((*front_node) == NULL) {
            (*front_node) = (*rear_node) = new_node;
        } else {

            (*rear_node)->next = new_node;
            (*rear_node) = new_node;
        }
    }
}

void dequeue(Node **front_node) {
    Node *delete_node;

    if ((*front_node) == NULL) {
        printf("Queue is empty.\n");
    } else {
        delete_node = (*front_node);
        (*front_node) = (*front_node)->next;
        free(delete_node);
    }
}

void displayQueue(Node *front_node) {
    Node *temp = front_node;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 5);

    dequeue(&front);

    displayQueue(front);

    return 0;
}
