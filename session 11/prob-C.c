#include<stdio.h>
#include<string.h>

void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapStr(char a[], char b[]){
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main(){
    
    FILE *plantfile = fopen("testdata.in", "r");
    int n;
    fscanf(plantfile, "%d", &n);
    char name[n][50];
    int num[n];
    
    for(int i = 0; i < n; i++){
        fscanf(plantfile, "%d#%[^\n]", &num[i], name[i]);
    }
    
    // DEBUG
    //    for(int i = 0; i < n; i++){
    //        printf("%d %s\n", num[i], name[i]);
    //    }
    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(strcmp(name[j], name[j + 1]) > 0){
                swapStr(name[j], name[j + 1]);
                swapInt(&num[j], &num[j + 1]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("%d %s\n", num[i], name[i]);
    }
    
    fclose(plantfile);
    
    return 0;
}