#include<stdio.h>

int main()
{
	int w, x, y, z ;
	float hasil_reamurA, hasil_fahrenheitA, hasil_kelvinA;
	float hasil_reamurB, hasil_fahrenheitB, hasil_kelvinB;
	float hasil_reamurC, hasil_fahrenheitC, hasil_kelvinC;
	
	scanf("%d %d %d %d", &w, &x, &y, &z);
	
	hasil_reamurA = x * 0.8;
	hasil_fahrenheitA = x * 1.8 + 32;
	hasil_kelvinA = x + 273;
	
	hasil_reamurB = y * 0.8;
	hasil_fahrenheitB = y * 1.8 + 32;
	hasil_kelvinB = y + 273;
	
	hasil_reamurC = z * 0.8;
	hasil_fahrenheitC = z * 1.8 + 32;
	hasil_kelvinC = z + 273;
	
	printf("%.2f %.2f %.2lf\n", hasil_reamurA, hasil_fahrenheitA, hasil_kelvinA);
	printf("%.2f %.2f %.2lf\n", hasil_reamurB, hasil_fahrenheitB, hasil_kelvinB);
	printf("%.2f %.2f %.2lf\n", hasil_reamurC, hasil_fahrenheitC, hasil_kelvinC);
	
	return 0;
	
}
