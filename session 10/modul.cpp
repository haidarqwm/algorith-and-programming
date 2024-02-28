#include <stdio.h>

void simpleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void intermediateSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {80, 40, 20, 76, 11, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array asli: ");
    printArray(arr, n);

    simpleSort(arr, n);
    printf("Array setelah pengurutan sederhana: ");
    printArray(arr, n);

    intermediateSort(arr, n);
    printf("Array setelah pengurutan menengah: ");
    printArray(arr, n);

    return 0;
}

