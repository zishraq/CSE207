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

void push(Node **node, int value) {
    Node *temp = (Node *) malloc(sizeof(Node));

    if (temp == NULL) {
        printf("Stack overflow!\n");
    } else {
        temp->data = value;
        temp->next = (*node);
        (*node) = temp;
    }
}

int pop(Node **node) {
    Node *delete_node;
    int x = -1;

    if ((*node) == NULL) {
        printf("Stack underflow!\n");
    } else {
        delete_node = (*node);
        (*node) = (*node)->next;
        x = delete_node->data;
        free(delete_node);
    }

    return x;
}

int isStackEmpty(Node *node) {
    return node ? 0 : 1;
}

void displayQueue(Node *front_node) {
    Node *temp = front_node;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void copyFromStack(Node **stack_top) {
    Node *front = NULL, *rear = NULL;

    while (!isStackEmpty((*stack_top))) {
        int x = pop(&(*stack_top));
        enqueue(&front, &rear, x);
    }

    displayQueue(front);
}

int main() {
    Node *stk_top = NULL;

    int n, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        push(&stk_top, element);
    }

    copyFromStack(&stk_top);

    return 0;
}
