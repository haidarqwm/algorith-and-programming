#include<stdio.h>

char kata1, kata2;
int S(int);

int main()
{
	
	int i, n, num;
	scanf("%d", &n);
	
	for(i=0 ; i<n ; i++)
	{
		scanf("%d %c %c", &num, &kata1, &kata2);
		printf("Case #%d: ", i+1);
		S(num);
		printf("\n");
	}
	return 0;
}

int S(int num)
{
	if(num==0)
	{
		printf("%c", kata1);
		return kata1;
	}
	
	else if(num==1)
	{
		printf("%c", kata2);
		return kata2;
	}
	
	else
	{
		int s = S(num-1) + S(num-2);
		return s;
	}	
}
