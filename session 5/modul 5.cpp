#include <stdio.h>

int factorial(int x) {
	if (x==0 || x==1) {
		return 1;
	} else {
		return x*factorial (x-1);
	}
}

int main() {
	int angka;
	printf("Masukkan bilangan bulat positif: ");
	scanf("%d", &angka);
	
	int hasil = factorial(angka);
	printf("Factorial dari %d adalah %d\n", angka, hasil);
	
	return 0;
}
