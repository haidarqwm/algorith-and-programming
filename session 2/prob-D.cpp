#include<stdio.h>

int main()
{
	int a, b;
	double hasil;
	
	scanf("%d %d", &a, &b);
	
	hasil = ((double)(a - b)/a)*100;
	
	printf("%.2lf%%\n", hasil);
	
	return 0;
}
