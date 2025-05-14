#include <stdio.h>

int searchMatrix(int matrix[][100], int n, int key) {
    int i = 0, j = n - 1;

    while (i < n && j >= 0) {
        if (matrix[i][j] == key)
            return 1;
        else if (matrix[i][j] > key)
            j--;
        else
            i++;
    }
    return 0;
}

int main() {
    int n, key;
    int matrix[100][100];

    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);
    printf("Enter matrix elements (row-wise sorted and column-wise sorted):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (searchMatrix(matrix, n, key))
        printf("Key %d found in matrix.\n", key);
    else
        printf("Key %d not found in matrix.\n", key);

    return 0;
}

