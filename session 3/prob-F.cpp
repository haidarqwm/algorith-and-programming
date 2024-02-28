#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int variasi = 0;
    
    for (int j = 0; j <= N; j++) {
        for (int l = 0; l <= N; l++) {
        	int b = N - j - l;
            if (b >= 0) {
            	variasi++;
			}
        }
    }

    printf("%d\n", variasi);

    return 0;
}
