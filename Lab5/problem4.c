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

int dequeue(Node **front_node) {
    int x = -1;

    Node *delete_node;

    if ((*front_node) == NULL) {
        printf("Queue is empty.\n");
    } else {
        delete_node = (*front_node);
        (*front_node) = (*front_node)->next;
        x = delete_node->data;
        free(delete_node);
    }

    return x;
}

int isQueueEmpty(Node *front_node) {
    if (front_node == NULL) {
        return 1;
    }
    return 0;
}

void displayQueue(Node *front_node) {
    Node *temp = front_node;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void copyQueue(Node **front_node) {
    Node *front_copy = NULL, *rear_copy = NULL;

    while (!isQueueEmpty((*front_node))) {
        int x = dequeue(&(*front_node));

        enqueue(&front_copy, &rear_copy, x);
    }

    displayQueue(front_copy);
}

int main() {
    int n, element;
    Node *front = NULL, *rear = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        enqueue(&front, &rear, element);
    }

    printf("Original queue: ");
    displayQueue(front);

    printf("Copied queue: ");
    copyQueue(&front);

    return 0;
}
