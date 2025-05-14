#include <stdio.h>

void rearrangeEvenOdd(int *arr, int size) {
    int *temp = (int *)malloc(size * sizeof(int));
    int *ptr = arr, *evenPtr = temp, *oddPtr;

    // First pass: store evens
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 == 0) {
            *evenPtr = *(ptr + i);
            evenPtr++;
        }
    }

    // Mark where odd elements will start
    oddPtr = evenPtr;

    // Second pass: store odds
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 != 0) {
            *oddPtr = *(ptr + i);
            oddPtr++;
        }
    }

    // Copy back to original array
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(temp + i);
    }

    free(temp);
}

// Example usage
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

