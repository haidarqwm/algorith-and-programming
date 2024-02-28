#include <stdio.h>

int main() {
    int N, M;
     
    scanf("%d %d", &N, &M);

    int tas[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &tas[i]);
    }

    int hapus[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &hapus[i]);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (tas[j] == hapus[i]) {
                tas[j] = -1; 
            }
        }
    }

    int maxNumber = -1;
    for (int i = 0; i < N; i++) {
        if (tas[i] != -1 && (maxNumber == -1 || tas[i] > maxNumber)) {
            maxNumber = tas[i];
        }
    }

    if (maxNumber != -1) {
        printf("Maximum number is %d\n", maxNumber);
    } else {
        printf("Maximum number is -1\n");
    }

    return 0;
}
