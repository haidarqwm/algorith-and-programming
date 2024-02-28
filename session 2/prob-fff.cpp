#include<stdio.h>

int main()
{
	int pd, md, pu;
	float hasil;
	
	scanf("%d %d %d", &pd, &md, &pu);
	
	hasil = (pd*0.20) + (md*0.30) + (pu*0.50);
	
	printf("%.2f\n", hasil);
	
	return 0;
}
