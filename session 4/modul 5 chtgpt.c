#include <stdio.h>

int main() {
    int n;
    printf("Masukkan jumlah elemen dalam array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("Elemen terbesar dalam array adalah: %d\n", largest);

    return 0;
}
