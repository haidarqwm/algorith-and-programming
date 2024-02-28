#include<stdio.h>

int main()
{
	int a, b, c, d ;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	printf("%.2f %.2f %.2lf\n", b*0.8, b*1.8 + 32, b+273);
	printf("%.2f %.2f %.2lf\n", c*0.8, c*1.8 + 32, c+273);
	printf("%.2f %.2f %.2lf\n", d*0.8, d*1.8 + 32, d+273);
	return 0;
	
}
