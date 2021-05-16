#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct charNode {
    char data;
    struct charNode *next;
} charNode;

void pushChar(charNode **node, char value) {
    charNode *temp = (charNode *) malloc(sizeof(charNode));

    if (temp == NULL) {
        printf("Stack overflow!\n");
    } else {
        temp->data = value;
        temp->next = (*node);
        (*node) = temp;
    }
}

char popChar(charNode **node) {
    charNode *delete_node;
    char x = -1;

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

int isCharNodeEmpty(charNode *node) {
    return node ? 0 : 1;
}

void isBalanced(char *exp) {
    charNode *stk = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            pushChar(&stk, exp[i]);
        } else if (exp[i] == ')') {
            if (isCharNodeEmpty(stk)) {
                printf("Closing parentheses not matched");
                return;
            }
            popChar(&stk);
        }
    }

    if (stk == NULL) {
        printf("Is balanced");
        return;
    } else {
        printf("Opening parentheses not matched");
        return;
    }
}

int main() {
    char *exp = (char *) malloc(100 * sizeof(char)); // = "(A+B)/C)";

    scanf("%s", exp);

    isBalanced(exp);

    return 0;
}
