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

    sum = *p_num1 + *p_num2;

    printf("The sum of the entered numbers is : %d\n", sum);

    return 0;
}