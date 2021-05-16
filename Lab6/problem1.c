#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, search, found = -1;

    printf("How many data do you want to input: \n");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    printf("Input the data: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &*(arr + i));
    }

    printf("What element do you want to search: ");
    scanf("%d", &search);

    for (int i = 0; i < size; i++) {
        if (*(arr + i) == search) {
            found = i + 1;
        }
    }

    if (found == -1) {
        printf("Not found");
    } else {
        printf("Your element is found in position %d\n", found + 1);
    }

    return 0;
}
