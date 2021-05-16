#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int *p_arr;

    printf("Input the number of elements to store in the array (max 10): ");
    scanf("%d", &n);

    p_arr = (int *) malloc(n * sizeof(int));

    if (n > 10) {
        printf("Array size is more than 10\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        printf("element %d: ", i + 1);
        scanf("%d", &*(p_arr + i));
        sum += *(p_arr + i);
    }

    printf("The sum of array is: %d\n", sum);

    return EXIT_SUCCESS;
}