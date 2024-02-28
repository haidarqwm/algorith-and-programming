#include <stdio.h>

int main() {
    int K;
    scanf("%d", &K); // Membaca jumlah testcase

    for (int i = 1; i <= K; i++) {
        int N, F;
        scanf("%d", &N); // Membaca jumlah pemain
        int MMR[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &MMR[j]); // Membaca MMR pemain
        }
        scanf("%d", &F); // Membaca MMR pemain yang ingin mencari party

        int MMR1 = -1, MMR2 = -1;
        for (int j = 0; j < N; j++) {
            if (MMR[j] < F && (MMR1 == -1 || MMR[j] > MMR1)) {
                MMR1 = MMR[j];
            } else if (MMR[j] > F && (MMR2 == -1 || MMR[j] < MMR2)) {
                MMR2 = MMR[j];
            }
        }

        printf("CASE #%d: %d %d\n", i, MMR1, MMR2);
    }

    return 0;
}
