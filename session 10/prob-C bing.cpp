#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int K;
    scanf("%d", &K);
    for(int i = 1; i <= K; i++) {
        int N, F;
        scanf("%d", &N);
        int MMR[N];
        for(int j = 0; j < N; j++) {
            scanf("%d", &MMR[j]);
        }
        scanf("%d", &F);
        qsort(MMR, N, sizeof(int), compare);
        int index = -1;
        for(int j = 0; j < N; j++) {
            if(MMR[j] == F) {
                index = j;
                break;
            }
        }
        if(index == -1) {
            printf("CASE #%d: -1 -1\n", i);
        } else if(index == 0) {
            printf("CASE #%d: %d %d\n", i, MMR[index], MMR[index+1]);
        } else if(index == N-1) {
            printf("CASE #%d: %d %d\n", i, MMR[index-1], MMR[index]);
        } else {
            printf("CASE #%d: %d %d\n", i, MMR[index], MMR[index+1]);
        }
    }
    return 0;
}

