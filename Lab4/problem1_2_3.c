#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct intNode {
    int data;
    struct intNode *next;
} intNode;

void pushInt(intNode **node, int value) {
    intNode *temp = (intNode *) malloc(sizeof(intNode));

    if (temp == NULL) {
        printf("Stack overflow!\n");
    } else {
        temp->data = value;
        temp->next = (*node);
        (*node) = temp;
        printf("Push successful!\n");
    }
}

int popInt(intNode **node) {
    intNode *delete_node;
    int x = -1;
 
    if ((*node) == NULL) {
        printf("Stack underflow!\n");
    } else {
        delete_node = (*node);
        (*node) = (*node)->next;
        x = delete_node->data;
        free(delete_node);
        printf("Pop successful!\n");
    }

    return x;
}

void display(intNode *node) {
    printf("___\n");
    while (node != NULL) {
        printf("%d  |\n", node->data);
        printf("___\n");
        node = node->next;
    }
    printf("\n");
}

int main() {
    int input;
    intNode *stk = NULL;

    do {
        printf("\n");
        printf("1.\tInsert data/ push stack\n");
        printf("2.\tPrint stack\n");
        printf("3.\tPop stack\n");
        printf("\n");


        printf("Option (-1 to exit): ");
        scanf("%d", &input);

        if (input == 1) {
            int x;
            printf("Enter an integer value: ");
            scanf("%d", &x);

            pushInt(&stk, x);

        } else if (input == 2) {
            display(stk);

        } else if (input == 3) {
            popInt(&stk);

        } else if (input == -1) {
            break;

        } else {
            printf("Choose one of the given option. \n");
        }
    } while (input);

    return EXIT_SUCCESS;
}
