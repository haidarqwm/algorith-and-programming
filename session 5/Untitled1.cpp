#include <stdio.h>

int rumus(int n, int *count) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 2;
    } else if (n % 5 == 0) {
        *count += 1;
        return n * 2;
    } else {
        return rumus(n - 1, count) + n + rumus(n - 2, count) + n - 2;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int count = 0;
        int result = rumus(N, &count);

        printf("Case #%d: %d %d\n", t, result, count);
    }

    return 0;
}
