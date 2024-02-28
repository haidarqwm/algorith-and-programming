#include<stdio.h>


int S(int, int, int);

int main()
{
	
	int i, n, num;
	int angka1, angka2;
	scanf("%d", &n);
	
	for(i=0 ; i<n ; i++)
	{
		scanf("%d %d %d", &num, &angka1, &angka2);
		printf("Case #%d: %d\n", i+1, S(num, angka1, angka2));
	}
	return 0;
}

int S(int num, int angka1, int angka2)
{
	if(num==0)
	{
		return angka1;
	}
	
	else if(num==1)
	{
		return angka2;
	}
	
	else
	{
		return S(num-1, angka1, angka2) - S(num-2, angka1, angka2);
	}	
}
