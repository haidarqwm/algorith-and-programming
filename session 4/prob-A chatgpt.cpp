#include <stdio.h>

int main() {
    int T; // Jumlah testcase
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N; // Jumlah bahan
        scanf("%d", &N);

        int A[N]; // Jumlah bahan yang dibutuhkan
        int B[N]; // Jumlah bahan yang dimiliki oleh Jojo

        // Membaca jumlah bahan yang dibutuhkan
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        // Membaca jumlah bahan yang dimiliki oleh Jojo
        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }

        // Menghitung dan menampilkan hasil
        printf("Case #%d:", t);
        for (int i = 0; i < N; i++) {
            int needed = A[i] - B[i];
            if (needed >= 0) {
                printf(" %d", needed);
            } else {
                printf(" -%d", -needed);
            }
        }
        printf("\n");
    }

    return 0;
}

