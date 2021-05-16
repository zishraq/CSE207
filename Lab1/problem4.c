#include <stdio.h>

void swap(int *num1, int *num2, int *num3) {
    int temp;
    temp = *num2;
    *num2 = *num1;
    *num1 = *num3;
    *num3 = temp;
}

int main() {
    int num1, num2, num3;

    int *p_num1, *p_num2, *p_num3;

    p_num1 = &num1;
    p_num2 = &num2;
    p_num3 = &num3;

    printf("Input the value of 1st element: ");
    scanf("%d", p_num1);

    printf("Input the value of 2nd element: ");
    scanf("%d", p_num2);

    printf("Input the value of 3rd element: ");
    scanf("%d", p_num3);

    printf("Value before swapping are: \n");
    printf("element 1: %d\n", *p_num1);
    printf("element 2: %d\n", *p_num2);
    printf("element 3: %d\n", *p_num3);

    swap(p_num1, p_num2, p_num3);

    printf("Value after swapping are: \n");
    printf("element 1: %d\n", *p_num1);
    printf("element 2: %d\n", *p_num2);
    printf("element 3: %d\n", *p_num3);

    return 0;
}