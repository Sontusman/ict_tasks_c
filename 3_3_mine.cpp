//Строганова С., 105 гр.
// Задача 3.3
// Вариант б
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double function(double x){
    return sin(2*x);
}

int main()
{
    FILE *file;
    file = fopen("3_3_mine_out.txt", "w");

    double step = 0.01;
    double start = -3.;
    double finish = 3.;

    fprintf(file, "x_i\t\tf(x_i)\t\tf'(x_i)\n");
    float mas[2][500];
    for(int i=0; i<(6/0.01); i++)
    {
        mas[0][i]= i*0.01-3;
        mas[1][i]= function(mas[0][i]);
        mas[2][i]= (function(mas[1][i] - step) - function(mas[1][i] + step)) / (2 * step);
        fprintf(file, "%f\t%f\t%f\n", mas[0][i], mas[1][i], mas[2][i]);
    }
    return 0;
}