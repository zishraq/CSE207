#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *head, *tail;

void create_doubly_linkedlist(int n);

void display();

void insert_node_at_the_beginning(int value);

void insert_node_at_the_end(int value);

void insert_node_at_the_middle(int value, int position);

int main() {
    int n;
    int new_value, position;

    printf("Input the number of nodes : ");
    scanf("%d", &n);

    create_doubly_linkedlist(n);

    printf("Before inserting New Node at the middle: \n");
    display();

    printf("Input the position: ");
    scanf("%d", &position);

    printf("Input the new data at the middle: ");
    scanf("%d", &new_value);

    insert_node_at_the_middle(new_value, position);

    printf("After inserting New Node at the middle: \n");
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

void insert_node_at_the_beginning(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
}

void insert_node_at_the_end(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    tail->next = newNode;
    tail = newNode;
}

void insert_node_at_the_middle(int value, int position) {
    int i;
    struct Node * newNode, *temp;

    temp = head;
    i=1;

    while(i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if(position == 1) {
        insert_node_at_the_beginning(value);

    } else if(temp == tail) {
        insert_node_at_the_end(value);

    } else if(temp != NULL) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;

        if(temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

    } else {
        printf(" The position you entered, is invalid.\n");
    }
}