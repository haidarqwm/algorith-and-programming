#include <stdio.h>

int main() {
    int N; // Jumlah teman
    scanf("%d", &N);

    int opinions[N]; // Opini teman
    for (int i = 0; i < N; i++) {
        scanf("%d", &opinions[i]);
    }

    int isEasy = 1; // Flag untuk menandakan apakah soal mudah atau tidak

    for (int i = 0; i < N; i++) {
        if (opinions[i] == 1) {
            isEasy = 0; // Jika ada teman yang berpikir soal susah, set flag menjadi 0
            break;
        }
    }

    // Output
    if (isEasy) {
        printf("easy\n");
    } else {
        printf("not easy\n");
    }

    return 0;
}

