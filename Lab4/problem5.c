#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    }

    return x;
}

int isIntNodeEmpty(intNode *node) {
    return node ? 0 : 1;
}

int decimal_to_binary_using_stack(int decimal) {
    intNode *stk = NULL;

    int binary = 0, i = 0;

    while (decimal != 0) {
        int remainder = decimal % 2;

        pushInt(&stk, remainder);

        decimal /= 2;
        i++;
    }

    while (!isIntNodeEmpty(stk)) {
        binary += popInt(&stk) * (int) pow(10, i - 1);
        i--;
    }

    return binary;
}

int main() {
    int decimal;

    scanf("%d", &decimal);

    int binary = decimal_to_binary_using_stack(decimal);

    printf("%d\n", binary);

    return 0;
}