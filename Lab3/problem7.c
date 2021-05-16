#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *head, *tail;

void create_doubly_linkedlist(int n);

void display();

void delete_node_at_the_beginning();

void delete_node_at_the_end();

void delete_node_at_the_middle(int position);

int main() {
    int n;
    int position;


    printf("Input the number of nodes : ");
    scanf("%d", &n);

    create_doubly_linkedlist(n);

    printf("Before deleting New Node at the middle: \n");
    display();

    printf("Input the position: ");
    scanf("%d", &position);

    delete_node_at_the_middle(position);

    printf("After deleting New Node at the middle: \n");
    display();

    return 0;
}

void create_doubly_linkedlist(int n) {
    if (n > 0) {
        head = (struct Node *) malloc(sizeof(struct Node));
        int value;

        printf("Input data for node 1: ");
        scanf("%d", &value);

        head->data = value;
        head->next = NULL;
        head->prev = NULL;
        tail = head;

        for (int i = 2; i <= n; i++) {
            struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

            printf("Input data for node %d: ", i);
            scanf("%d", &value);

            newNode->data = value;
            newNode->prev = tail;
            newNode->next = NULL;

            tail->next = newNode;
            tail = newNode;

        }
    }
}

void display() {
    struct Node *temp;
    temp = head;

    printf("Data entered on the list are : \n");
    int i = 1;
    while (temp != NULL) {
        printf("node %d: %d \n", i, temp->data);
        i++;
        temp = temp->next;
    }
    printf("\n");
}

void delete_node_at_the_beginning() {
    struct Node *deleteNode = head;

    head = head->next;
    head->prev = NULL;
    free(deleteNode);
}

void delete_node_at_the_end() {
    struct Node *deleteNode = tail;

    tail = tail->prev;
    tail->next = NULL;
    free(deleteNode);
}

void delete_node_at_the_middle(int position) {
    struct Node *currentNode;
    int i;

    currentNode = head;
    for(i=1; i < position && currentNode != NULL; i++) {
        currentNode = currentNode->next;
    }

    if(position == 1) {
        delete_node_at_the_beginning();

    } else if(currentNode == tail) {
        delete_node_at_the_end();

    } else if(currentNode != NULL) {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;

        free(currentNode);

    } else {
        printf("The position is invalid!\n");
    }
}