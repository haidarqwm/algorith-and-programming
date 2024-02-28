#include <stdio.h>
#include <math.h>

int main()
{
    double num1, num2;

    printf("masukkan dua angka: ");
    scanf("%lf %lf", &num1, &num2);

    printf("penjumlahan: %.2lf\n", num1 + num2);
    printf("perkalian: %.2lf\n", num1 * num2);
    printf("pengurangan: %.2lf\n", num1 - num2);

    if (num2 != 0)
	{
        printf("pembagian: %.2lf\n", num1 / num2);
        printf("sisa bagi: %.2lf\n", fmod(num1, num2));
    } 
	
	else
	{
        printf("pembagian oleh nol tidak diperbolehkan\n");
    }

    return 0;
}
