#include <stdio.h>

void rearrangeEvenOdd(int *arr, int size) {
    int *temp = (int *)malloc(size * sizeof(int));
    int *ptr = arr, *evenPtr = temp, *oddPtr;

    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 == 0) {
            *evenPtr = *(ptr + i);
            evenPtr++;
        }
    }

    oddPtr = evenPtr;

    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 != 0) {
            *oddPtr = *(ptr + i);
            oddPtr++;
        }
    }

    for (int i = 0; i < size; i++) {
        *(arr + i) = *(temp + i);
    }

    free(temp);
}

int main() {
    int arr[] = {1, 2, 4, 7, 6, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    rearrangeEvenOdd(arr, size);

    printf("Rearranged array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    return 0;
}

