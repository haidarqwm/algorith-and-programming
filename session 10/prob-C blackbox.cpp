#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mmr;
    int index;
} Player;

int compare(const void *a, const void *b) {
    return ((Player *)a)->mmr - ((Player *)b)->mmr;
}

void find_party(int N, int players_mmr[], int F) {
    Player *player = (Player *)malloc(N * sizeof(Player));
    int i;
    for (i = 0; i < N; i++) {
        player[i].mmr = players_mmr[i];
        player[i].index = i;
    }

    qsort(player, N, sizeof(Player), compare);

    int i_min, i_max;
    i_min = 0;
    i_max = N - 1;

    while (i_min < i_max) {
        if (player[i_min].mmr + player[i_max].mmr == F) {
            printf("CASE #%d: [%d] [%d]\n", player[i_min].index + 1, player[i_min].mmr, player[i_max].mmr);
            break;
        } else if (player[i_min].mmr + player[i_max].mmr < F) {
            i_min++;
        } else {
            i_max--;
        }
    }

    if (i_min == i_max) {
        printf("CASE #%d: -1 -1\n", player[i_min].index + 1);
    }

    free(player);
}

int main() {
    int K, N, F, i, j;
    scanf("%d", &K);

    for (i = 0; i < K; i++) {
        scanf("%d", &N);
        int players_mmr[N];
        for (j = 0; j < N; j++) {
            scanf("%d", &players_mmr[j]);
        }
        scanf("%d", &F);
        printf("CASE #%d:\n", i + 1);
        find_party(N, players_mmr, F);
    }

    return 0;
}
