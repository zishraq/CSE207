#include <stdio.h>

int main() {
    int num1, num2, sum;

    int *p_num1, *p_num2;

    p_num1 = &num1;
    p_num2 = &num2;

    printf("Input the first number: ");
    scanf("%d", p_num1);

    printf("Input the second number: ");
    scanf("%d", p_num2);

    if (*p_num1 > *p_num2) {
        printf("%d is the maximum number.\n", *p_num1);
    } else {
        printf("%d is the maximum number.\n", *p_num2);
    }

    return 0;
}