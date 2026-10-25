
#include <stdio.h>

char papan[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void tampilkanPapan() {
    printf("\n");
    printf(" %c | %c | %c\n", papan[0][0], papan[0][1], papan[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", papan[1][0], papan[1][1], papan[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", papan[2][0], papan[2][1], papan[2][2]);
    printf("\n");
}

int cekMenang() {
    int i;

    for (i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] &&
            papan[i][1] == papan[i][2])
            return 1;

        if (papan[0][i] == papan[1][i] &&
            papan[1][i] == papan[2][i])
            return 1;
    }

    if (papan[0][0] == papan[1][1] &&
        papan[1][1] == papan[2][2])
        return 1;

    if (papan[0][2] == papan[1][1] &&
        papan[1][1] == papan[2][0])
        return 1;

    return 0;
}

int main() {
    int pilihan, langkah = 0;
    char pemain = 'X';

    printf("=== PERMAINAN TIC TAC TOE ===\n");
    printf("Pemain X melawan Pemain O\n");

    while (langkah < 9) {
        tampilkanPapan();

        printf("Giliran pemain %c\n", pemain);
        printf("Pilih kotak (1-9): ");

        if (scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka!\n");
            return 1;
        }

        if (pilihan < 1 || pilihan > 9) {
            printf("Pilihan tidak valid!\n");
            continue;
        }

        int baris = (pilihan - 1) / 3;
        int kolom = (pilihan - 1) % 3;

        if (papan[baris][kolom] == 'X' ||
            papan[baris][kolom] == 'O') {
            printf("Kotak sudah terisi! Pilih yang lain.\n");
            continue;
        }

        papan[baris][kolom] = pemain;
        langkah++;

        if (cekMenang()) {
            tampilkanPapan();
            printf("SELAMAT! Pemain %c MENANG!\n", pemain);
            return 0;
        }

        if (pemain == 'X')
            pemain = 'O';
        else
            pemain = 'X';
    }

    tampilkanPapan();
    printf("Permainan SERI!\n");

    return 0;
}
