#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

int Rotate(int x, int n){
    return (x<<n)|(x>>(8-n));
}

int main(){
    char l[255]={0};
    int N;
    printf("Enter the length of the shift:\n");
    scanf("%d", &N);
    FILE *file_read;
    FILE *file_write;
    file_read = fopen("7_1_read.txt", "r");
    file_write = fopen("7_1_write.txt", "w");
    fgets(l, 255, file_read);
    for(int i=0; i<16; i++){
        int d = atoi(l);
        fprintf(file_write, "%d\n", Rotate(d, N));
        fgets(l, 255, file_read);
    }
    fclose(file_read); //закрыли файл
    fclose(file_write);
    return 0;
}