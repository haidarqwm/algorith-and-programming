#include <stdio.h>

int main() {
    int N, Q;

    scanf("%d", &N);
   

    int array[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    scanf("%d", &Q);

    for (int query = 1; query <= Q; query++) {
        long long M;

        scanf("%lld", &M);

        int kiri = 0, kanan = 0;
        long long sum = 0;
        int maxLength = 0;

        while (kanan < N) {
            sum += array[kanan];

            while (sum > M) {
                sum -= array[kiri];
                kiri++;
            }

            int length = kanan - kiri + 1;

            if (length > maxLength) {
                maxLength = length;
            }

            kanan++;
        }

        printf("Case #%d: %d\n", query, maxLength);
    }


    return 0;
}
