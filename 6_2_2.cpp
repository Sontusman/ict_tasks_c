#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main()
{
    char l[255]={0};
    FILE *file_read;
    FILE *file_write; //объявили файл
    file_read = fopen("function_values_read.txt", "r"); 
    file_write = fopen("function_values_write.txt", "w");
    fgets(l, 255, file_read); //игнорируем 1ю строчку
    fgets(l, 255, file_read);
    for(int i=0; i<600; i++){
        char x[20]={0};
        char F_x[20]={0};
        char f_x[20]={0};
        strncpy(x, l+2, 8);
        strncpy(F_x, l+17, 8);
        strncpy(f_x, l+32, 8);
        fprintf(file_write, "%s\t%s\t%s\n", x, F_x, f_x);
        fgets(l, 255, file_read);
    }

    fclose(file_read); //закрыли файл
    fclose(file_write);
    return 0;
}