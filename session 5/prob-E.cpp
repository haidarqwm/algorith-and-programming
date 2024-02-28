#include <stdio.h>

int findFibonacciK(int F0, int F1, int K) {
    if (K == 0) return F0;
    if (K == 1) return F1;
    
    int current, prev1 = F1, prev2 = F0;
    
    for (int i = 2; i <= K; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main() {
    int F0, F1, K;
    scanf("%d %d %d", &F0, &F1, &K);

    int result = findFibonacciK(F0, F1, K);
    printf("%d\n", result);

    return 0;
}
