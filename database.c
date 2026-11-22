#include <stdio.h>
#include <string.h>

#define MAX_MHS 50
#define MAX_MK 50
#define MAX_KRS 200

typedef struct {
    char nim[20];
    char nama[50];
} Mahasiswa;

typedef struct {
    char kode_matkul[15];
    char nama_matkul[50];
    int sks;
} Matkul;

typedef struct {
    char nim[20];
    char kode_matkul[15];
    int sks;
} KRS;

int main() {
    Mahasiswa mhs[MAX_MHS];
    Matkul mk[MAX_MK];
    KRS krs[MAX_KRS];

    int jml_mhs = 0;
    int jml_mk = 0;
    int jml_krs = 0;
    int pilihan;

    do {
        printf("\n=== MENU DATABASE AKADEMIK ===\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tambah Mata Kuliah\n");
        printf("3. Input KRS\n");
        printf("4. Lihat Semua Data KRS\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // buang karakter newline sisa scanf

        if (pilihan == 1) {
            if (jml_mhs < MAX_MHS) {
                printf("Masukkan NIM: ");
                fgets(mhs[jml_mhs].nim, sizeof(mhs[jml_mhs].nim), stdin);
                mhs[jml_mhs].nim[strcspn(mhs[jml_mhs].nim, "\n")] = '\0';

                printf("Masukkan Nama: ");
                fgets(mhs[jml_mhs].nama, sizeof(mhs[jml_mhs].nama), stdin);
                mhs[jml_mhs].nama[strcspn(mhs[jml_mhs].nama, "\n")] = '\0';

                jml_mhs++;
                printf("Data mahasiswa tersimpan!\n");
            } else {
                printf("Kapasitas data mahasiswa penuh.\n");
            }
        } else if (pilihan == 2) {
            if (jml_mk < MAX_MK) {
                printf("Masukkan Kode Matkul: ");
                fgets(mk[jml_mk].kode_matkul, sizeof(mk[jml_mk].kode_matkul), stdin);
                mk[jml_mk].kode_matkul[strcspn(mk[jml_mk].kode_matkul, "\n")] = '\0';

                printf("Masukkan Nama Matkul: ");
                fgets(mk[jml_mk].nama_matkul, sizeof(mk[jml_mk].nama_matkul), stdin);
                mk[jml_mk].nama_matkul[strcspn(mk[jml_mk].nama_matkul, "\n")] = '\0';

                printf("Masukkan Jumlah SKS: ");
                scanf("%d", &mk[jml_mk].sks);
                getchar();

                jml_mk++;
                printf("Data mata kuliah tersimpan!\n");
            } else {
                printf("Kapasitas data mata kuliah penuh.\n");
            }
        } else if (pilihan == 3) {
            if (jml_krs < MAX_KRS) {
                char kode_cari[15];
                int ditemukan = -1;

                printf("Masukkan NIM Mahasiswa: ");
                fgets(krs[jml_krs].nim, sizeof(krs[jml_krs].nim), stdin);
                krs[jml_krs].nim[strcspn(krs[jml_krs].nim, "\n")] = '\0';

                printf("Masukkan Kode Matkul: ");
                fgets(kode_cari, sizeof(kode_cari), stdin);
                kode_cari[strcspn(kode_cari, "\n")] = '\0';

                // Cari SKS otomatis berdasarkan kode matkul yang sudah diinput
                for (int i = 0; i < jml_mk; i++) {
                    if (strcmp(mk[i].kode_matkul, kode_cari) == 0) {
                        ditemukan = i;
                        break;
                    }
                }

                if (ditemukan != -1) {
                    strcpy(krs[jml_krs].kode_matkul, mk[ditemukan].kode_matkul);
                    krs[jml_krs].sks = mk[ditemukan].sks;
                    jml_krs++;
                    printf("KRS berhasil dicatat (%d SKS)!\n", mk[ditemukan].sks);
                } else {
                    printf("Kode matkul tidak ditemukan. Input mata kuliah dulu di menu 2.\n");
                }
            } else {
                printf("Kapasitas data KRS penuh.\n");
            }
        } else if (pilihan == 4) {
            printf("\n--- DAFTAR KRS ---\n");
            if (jml_krs == 0) {
                printf("Belum ada data KRS.\n");
            } else {
                for (int i = 0; i < jml_krs; i++) {
                    printf("%d. NIM: %s | Kode Matkul: %s | SKS: %d\n",
                           i + 1, krs[i].nim, krs[i].kode_matkul, krs[i].sks);
                }
            }
        } else if (pilihan != 0) {
            printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    printf("Program selesai.\n");
    return 0;
}
