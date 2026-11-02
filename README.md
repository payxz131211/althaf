#include <stdio.h>

int main() {
    int A[4][4];
    int X[4];
    int Y[4];
    int i, j;

    printf("PROGRAM PERKALIAN MATRIKS\n");

    // Input matriks A
    printf("\nMasukkan elemen matriks A (4x4):\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Input vektor X
    printf("\nMasukkan elemen vektor X:\n");

    for (i = 0; i < 4; i++) {
        printf("X[%d] = ", i);
        scanf("%d", &X[i]);
    }

    // Perkalian matriks dengan vektor
    for (i = 0; i < 4; i++) {
        Y[i] = 0;

        for (j = 0; j < 4; j++) {
            Y[i] += A[i][j] * X[j];
        }
    }

    // Menampilkan hasil
    printf("\nHasil perkalian matriks A x X:\n");

    for (i = 0; i < 4; i++) {
        printf("Y[%d] = %d\n", i, Y[i]);
    }

    return 0;
}
