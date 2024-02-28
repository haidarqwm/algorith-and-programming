#include <stdio.h> 
	
	int e = 0;
	int rumus(int s) {
	int f;
	if (s==0)
	return 1;
	
		else if (s==1)
		return 2;
		
	else if (s % 5 == 0)
	return s * 2;
	
	else {
		if (s % 3 ==0) e += 1;
		f = rumus(s-1)+s+rumus(s-2)+s-2;
	}
	return f;
}

	int main () {
	
		int a, s;
		
	scanf ("%d", &a);
for (int i=0; i<a; i++) {
		
		scanf("%d", &s);
		rumus(s);
		printf ("Case #%d: ", i+1);
		printf ("%d %d", rumus(s), e);
		printf ("\n");
		e=0;
}

return 0;

}
