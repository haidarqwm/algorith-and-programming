#include <stdio.h>

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    if (N > M) {
        int temp = N;
        N = M;
        M = temp;
    }

    int current = N;

    while (current <= M) {
        printf("%d\n", current);
        current++;
    }

    return 0;
}

