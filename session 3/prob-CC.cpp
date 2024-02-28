#include <stdio.h>

int main() {
	int T;
	
	scanf("%d", &T);
	
	for (int i = 1; i <= T; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		if (A > B) {
			printf("Case #%d: Go-Jo\n", i);
		} else {
			printf("Case #%d: Bi-Pay\n", i);
		}
 	}
	
	return 0;
}
