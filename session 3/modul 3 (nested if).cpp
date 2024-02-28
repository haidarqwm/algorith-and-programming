#include <stdio.h>

int main() 
{
    int a, b, c;
    
    printf("masukkan tiga bilangan: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a >= b) {
        if (a >= c) {
            printf("bilangan terbesarnya adalah %d\n", a);
        }
        else {
            printf("bilangan terbesarnya adalah %d\n", c);
        }
    }
    else {
        if (b >= c) {
            printf("bilangan terbesarnya adalah %d\n", b);
        }
        else {
            printf("bilangan terbesarnya adalah %d\n", c);
        }
    }
    
    return 0;
}
