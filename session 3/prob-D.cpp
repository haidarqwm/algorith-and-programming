#include <stdio.h>

int main() {
	int T;
	
	scanf("%d", &T);
	
	for (int i = 1; i <= T; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		int N = A;
		while (A >= B) {
			int penukaran = A / B;
			N += penukaran;
			A = penukaran + (A % B);
		} 
		
		printf("Case #%d: %d\n", i, N);
 	}
	
	return 0;
}
