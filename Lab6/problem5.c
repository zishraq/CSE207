#include <stdio.h>
#include <stdlib.h>


void reverse_insertion_sort(int *arr, int size);

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

    reverse_insertion_sort(arr, size);

    printArray(arr, size);

    return 0;
}

void reverse_insertion_sort(int *arr, int size) {
    int x;

    for (int i = 1; i < size; i++) {
        int j = i - 1;
        x = arr[i];

        while (j > -1 && x > arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void printArray(int *arr, int size) {
    printf("Sorted list in reverse order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
