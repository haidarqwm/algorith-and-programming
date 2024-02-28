#include <stdio.h>

int main ()
{
	int arr[9] = {51, 1089, 6773, 71, 97, 4005, -1, 10};
		int max = arr[0];
		int index;
			for(int i = 1; i < 9; i++){
				if(arr[i] > max){
					max = arr[i];
			 	index = i;
				}
			}
		printf("max = %d\n", max);
		printf("%d\n", index);
	
	return 0;
	
}
