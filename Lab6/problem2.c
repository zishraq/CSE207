#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int search, int first, int last);

void swap(int *num1, int *num2);

void bubble_sort(int *arr, int size);

int main() {
    int size, search, found;

    printf("How many data do you want to input: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    printf("Input the data: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &*(arr + i));
    }

    bubble_sort(arr, size);

    printf("What element do you want to search: ");
    scanf("%d", &search);

    found = binary_search(arr, search, 0, size - 1);

    if (found == -1) {
        printf("Not found");
    } else {
        printf("Your element is found in position %d\n", found + 1);
    }

    return 0;
}

int binary_search(int *arr, int search, int first, int last) {
    while (first <= last) {
        int middle = first + (last - first) / 2;

        if (*(arr + middle) == search) {
            return middle;

        }

        if (*(arr + middle) < search) {
            first = middle + 1;

        } else {
            last = middle - 1;
        }
    }

    return -1;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap(&*(arr + j), &*(arr + j + 1));
            }
        }
    }
}
