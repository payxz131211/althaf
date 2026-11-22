#include <stdio.h>

int main() {
    // Matriks 4x4
    int matrix_4x4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 3, 2, 1}
    };

    // Matriks 4x1
    int matrix_4x1[4][1] = {
        {10},
        {20},
        {30},
        {40}
    };

    // Matriks hasil (ukuran 4x1), diinisialisasi 0
    int hasil[4][1] = {0};

    // Proses Perkalian Matriks
    for (int i = 0; i < 4; i++) {         // Baris matriks A (4x4)
        for (int j = 0; j < 1; j++) {     // Kolom matriks B (4x1)
            for (int k = 0; k < 4; k++) { // Penjumlahan perkalian elemen
                hasil[i][j] += matrix_4x4[i][k] * matrix_4x1[k][j];
            }
        }
    }

    // Menampilkan Hasil
    printf("Hasil Perkalian Matriks (4x1):\n");
    for (int i = 0; i < 4; i++) {
        printf("[%d]\n", hasil[i][0]);
    }

    return 0;
}
