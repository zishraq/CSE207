#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert_at_the_beginning(Node **node, int value);

void insert_at_the_end(Node **node, int value);

void insert_at_the_middle(Node **node, int value, int index);

void delete_from_the_beginning(Node **node);

void delete_from_the_end(Node **node);

void delete_from_the_middle(Node **node, int index);

int count(Node *node);

void display(Node *node);

int search(Node *node, int search);

int main() {
    int input;
    Node *head = NULL;

    do {
        printf("Please insert your option: \n");
        printf("\t1. Insert Node at the beginning \n");
        printf("\t2. Insert Node at the end \n");
        printf("\t3. Insert Node at the Middle \n");
        printf("\t4. Delete Node from beginning \n");
        printf("\t5. Delete Node from End \n");
        printf("\t6. Delete Node from Middle \n");
        printf("\t7. Display the List \n");
        printf("\t8. Find a Value From the List \n");
        printf("\t9. Exit your code \n");

        printf("\nOption: ");
        scanf("%d", &input);

        if (input == 1) {
            int value;

            printf("Enter Value: ");
            scanf("%d", &value);

            insert_at_the_beginning(&head, value);

        } else if (input == 2) {
            int value;

            printf("Enter Value: ");
            scanf("%d", &value);

            insert_at_the_end(&head, value);

        }

        else if (input == 3) {
            int value, index;

            printf("Enter Index: ");
            scanf("%d", &index);

            printf("Enter Value: ");
            scanf("%d", &value);

            insert_at_the_middle(&head, value, index);
        }

        else if (input == 4) {
            delete_from_the_beginning(&head);
        }

        else if (input == 5) {
            delete_from_the_end(&head);
        }

        else if (input == 6) {
            int index;

            printf("Enter Index: ");
            scanf("%d", &index);

            delete_from_the_middle(&head, index);
        }

        else if (input == 7) {
            display(head);
        }

        else if (input == 8) {
            int value;

            printf("Enter Search Value: ");
            scanf("%d", &value);

            int index = search(head, value);

            if (index == -1) {
                printf("Value not found or invalid index\n");
            } else {
                printf("Found at %d\n", index);
            }
        }

        else if (input == 9) {
            printf("Exit Code!\n");
            break;
        }

        else {
            printf("Your Input is wrong, please choice between 1-9\n");
        }

    } while (input);

    return EXIT_SUCCESS;
}

void insert_at_the_beginning(Node **node, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Failed to allocate memory.\n");
    } else {
        new_node->data = value;
        new_node->next = (*node);
        (*node) = new_node;

        printf("Insertion Successful!\n");
    }
}

void insert_at_the_end(Node **node, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Failed to allocate memory.\n");
    } else {
        new_node->data = value;
        new_node->next = NULL;

        if ((*node) == NULL) {
            (*node) = new_node;
        } else {
            Node *temp_node = (*node);

            while (temp_node->next != NULL) {
                temp_node = temp_node->next;
            }
            temp_node->next = new_node;
        }
        printf("Insertion Successful!\n");
    }
}

void insert_at_the_middle(Node **node, int value, int index) {
    Node *new_node;

    if (index < 0 || index > count((*node))) {
        printf("Invalid Index.\n");
    } else {

        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;

        if (index == 0) {
            new_node->next = (*node);
            (*node) = new_node;
        } else {
            Node *temp_node = (*node);

            for (int i = 0; i < index - 1; i++) {
                temp_node = temp_node->next;
            }

            new_node->next = temp_node->next;
            temp_node->next = new_node;
        }
        printf("Insertion Successful!\n");
    }
}

void delete_from_the_beginning(Node **node) {
    if ((*node) != NULL) {
        Node *delete_node = (*node);

        (*node) = (*node)->next;
        free(delete_node);

        printf("Delete Successful!\n");
    } else {
        printf("List is empty, Insert some value first. \n");
    }
}

void delete_from_the_middle(Node **node, int index)  {
    Node *delete_node = (*node), *prev_node = NULL;

    if ((*node) != NULL) {
        if (index >= 0 || index < count((*node))) {
            if (index == 0) {
                (*node) = (*node)->next;
                free(delete_node);
            } else {
                for (int i = 0; i < index; i++) {
                    prev_node = delete_node;
                    delete_node = delete_node->next;
                }

                prev_node->next = delete_node->next;
                free(delete_node);
            }
        }

        printf("Delete Successful!\n");
    } else {
        printf("List is empty, Insert some value first. \n");
    }
}

void delete_from_the_end(Node **node) {
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

        printf("Delete Successful!\n");
    } else {
        printf("List is empty, Insert some value first. \n");
    }
}

int count(Node *node) {
    int i = 0;

    while(node) {
        i++;
        node = node->next;
    }

    return i;
}

void display(Node *node) {
    if (node == NULL) {
        printf("List is empty, Insert some value first. \n");
    } else {
        int index = 0;
        while (node != NULL) {
            printf("Data[%d] = %d\n", index, node->data);
            node = node->next;
            index++;
        }
    }
}

int search(Node *node, int search) {
    int index = -1, found = 0;

    if (node == NULL) {
        return index;
    } else {
        index = 0;
        while (node != NULL) {
            if (node->data == search) {
                found = 1;
                break;
            }

            node = node->next;
            index++;
        }

        if (found == 1) {
            return index;
        } else {
            return -1;
        }
    }
}
