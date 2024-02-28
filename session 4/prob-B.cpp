#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int X;
        scanf("%d", &X);

        int array[X][X];

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < X; j++) {
                scanf("%d", &array[i][j]);
            }
        }

        int columnSum[X];
        for (int i = 0; i < X; i++) {
            columnSum[i] = 0;
            for (int j = 0; j < X; j++) {
                columnSum[i] += array[j][i];
            }
        }

        printf("Case #%d:", t);
        for (int i = 0; i < X; i++) {
            printf(" %d", columnSum[i]);
        }
        printf("\n");
    }

    return 0;
}

