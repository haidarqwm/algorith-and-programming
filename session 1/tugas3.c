#include <stdio.h>

int main()
{
	int num1, num2;
	
	printf("num1:\n");
	scanf("%d", &num1);
	printf("num2:\n");
	scanf("%d", &num2);
	
	int hasil = num1 + num2;
	
	printf("jumlah dari kedua angka di atas adalah = %d\n", hasil);
	
	return(0);
}
