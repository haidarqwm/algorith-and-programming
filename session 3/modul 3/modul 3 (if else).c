#include <stdio.h>

int main()
{
	int a, b, c;
	
	printf("masukkan tiga bilangan: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if (a>=b && a>=c) {
		printf("bilangan terbesarnya adalah %d", a);
	}
	else if (b>=a && b>=c) {
		printf("bilangan terbesarnya adalah %d", b);
	}
	else {
		printf("bilangan terbesarnya adalah %d", c);
	}
	
	return 0;
}
