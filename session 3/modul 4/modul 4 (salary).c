#include <stdio.h>

int main() {
    double sales;
    double salary;

    printf("Enter sales in dollars (-1 to end): ");
    scanf("%lf", &sales);

    while (sales != -1) {
        salary = 200.0 + (0.09 * sales);
        printf("Salary is: $%.2lf\n", salary);

        printf("Enter sales in dollars (-1 to end): ");
        scanf("%lf", &sales);
    }

    return 0;
}
