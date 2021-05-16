#include <stdio.h>
#include <stdlib.h>


void swap(int *num1, int *num2);

void selection_sort(int *arr, int size);

void printArray(int *arr, int size);

int main() {
    int size;

    printf("How many data do you want to input: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    printf("Input the data: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &*(arr + i));
    }

    selection_sort(arr, size);

    printArray(arr, size);

    return 0;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_value_idx = i;

        for (int j = i + 1; j < size; j++) {
            if (*(arr + min_value_idx) > *(arr + j)) {
                min_value_idx = j;
            }
        }

        swap(&*(arr + min_value_idx), &*(arr + i));
    }
}

void printArray(int *arr, int size) {
    printf("Sorted list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
