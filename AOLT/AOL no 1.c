#include <stdio.h>
#include <string.h>

void reverseAndInvert(char *str) {
    int size = strlen(str);
    
    // untuk membalikkan string
    for (int i = 0, j =  size - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // untuk mengubah karakter
    for (int i = 0; i < size; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // untuk mengubah huruf kecil menjadi huruf besar
            str[i] = str[i] - ('a' - 'A');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // untuk mengubah huruf besar menjadi huruf besar
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int main() {
    char input[101];

    printf("Masukkan string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int length = strlen(input);
    if (length < 1 || length > 100) {
        printf("Panjang input invalid. Tolong masukkan string dengan panjang 1 hingga 100.\n");
        return 1;
    }
    reverseAndInvert(input);
    printf("String setelah dikonversi: %s\n", input);

    return 0;
}
