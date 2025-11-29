#include <stdio.h>
#include <stdlib.h>
int main() {
    int m, n, o, p;
    int i, j, k;
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &m);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &n);
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &o);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &p);
    int **A = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
        A[i] = (int*)malloc(n * sizeof(int));
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    printf("\nMatrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    int **B = (int**)malloc(o * sizeof(int*));
    for (i = 0; i < o; i++)
        B[i] = (int*)malloc(p * sizeof(int));
    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < o; i++)
        for (j = 0; j < p; j++)
            scanf("%d", &B[i][j]);
    printf("\nMatrix B:\n");
    for (i = 0; i < o; i++) {
        for (j = 0; j < p; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    if (n != o) {
        printf("\nMatrix multiplication is NOT possible.\n");
    } else {
        int **C = (int**)malloc(m * sizeof(int*));
        for (i = 0; i < m; i++)
            C[i] = (int*)malloc(p * sizeof(int));
        for (i = 0; i < m; i++)
            for (j = 0; j < p; j++)
                C[i][j] = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < p; j++)
                for (k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
        printf("\nResultant Matrix C:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
        for (i = 0; i < m; i++)
            free(C[i]);
        free(C);
    }
    for (i = 0; i < m; i++)
        free(A[i]);
    free(A);
    for (i = 0; i < o; i++)
        free(B[i]);
    free(B);
    return 0;
}

