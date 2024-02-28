#include <stdio.h>

void count(int num[], int index, int n, int path) 
{
	if (index >= n)
	{
		return;
	}
	
	int leftindex = 2 * index + 1;
	int rightindex = 2 * index +2;
	
	int currentsum = path + num[index];
	
	if (leftindex >= n && rightindex >= n)
	{
		printf("%d\n", currentsum);
		return;
	}
	
	count(num, leftindex, n, currentsum);
	count(num, rightindex, n, currentsum);
	
}

int main()
{
	int i, rep, rep1, n;
	scanf("%d", &i);
	
	for (rep=0 ; rep<i ; rep++)
	{
		scanf("%d", &n);
		int num[n];
		for(rep1=0 ; rep1<n ; rep1++)
		{
			scanf("%d", &num[rep1]);
		}
		
		printf("Case #%d:\n", rep+1);
		count(num, 0, n, 0);
	}
	return 0;
}
