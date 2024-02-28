#include<stdio.h>

int score = 0;


int f(int n)
{
	score++;
	if(n==0)
	{
		return 1;
	}
	else if(n==1)
	{
		return 2;
	}
	else
	{
		return f(n-1) + n + f(n-2) + (n-2);
	
	}
	
}

int main()
{
	int n, rep, i;
	
	
	scanf("%d", &rep);
	
	for(i=0 ; i<rep ; i++)
	{
		scanf("%d", &n);
		int hasil = f(n);
		printf("Case #%d: %d\n", i+1, score);
		score = 0;
	}
	return 0;
}
