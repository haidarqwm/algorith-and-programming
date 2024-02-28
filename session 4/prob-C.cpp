#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        char S[1000];
        scanf("%s", S);

        int len = strlen(S);

        for (int i = 0; i < len; i++) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                S[i] = S[i] - 'a' + 'A';
            } else if (S[i] >= 'A' && S[i] <= 'Z') {
				S[i] = S[i] - 'A' + 'a';
			}
        }

        for (int i = 0; i < len / 2; i++) {
            char temp = S[i];
            S[i] = S[len - i - 1];
            S[len - i - 1] = temp;
        }

        printf("Case #%d: %s\n", t, S);
        
    }

    return 0;
}
