#include<stdio.h>

int main()
{
	int a, b;
	double hasil;
	
	scanf("%d %d", &a, &b);
	
	hasil = ((double)b/a)*100;
	
	printf("%.4lf%%\n", hasil);
	
	return 0;
	
}
