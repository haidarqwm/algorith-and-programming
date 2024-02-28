#include <stdio.h>

int main() {
	int T;
	
	scanf("%d", &T);
	
	for (int i = T; i <= T; i++) {
		int A, B, C, D;
		scanf("%d %d %d %d", &A, &B, &C, &D);
		if (A+B > C+D) {
			printf("Case #%d: Bi-Pay\n", i);
			printf("Case #%d: Go-Jo\n", i);
		} else {
			printf("Case #%d: Go-Jo\n", i);
			printf("Case #%d: Bi-Pay\n", i);
		}
 	}
	
	return 0;
}
