//Строганова С.С. 105 группа
//6.2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float f(float x)
{
    float y;
    y = pow(cos(x), 2);
    return y;
}

int main()
{
    FILE *file;
    file = fopen("function_values.txt", "w");
    float h, left_border, right_border;
    float function_values[596][3];
    int i1, i2;
    printf("input step, left border, right border\n");
    scanf("%f %f %f", &h, &left_border, &right_border);
    printf("%d", int((right_border - left_border)/h));
    i1 = (int)(left_border / h);
    i2 = (int)(right_border / h);
    fprintf(file, "x_i\tf(x_i)\tderivative(x_i)\n");
    for (int i = i1; i < i2; i++)
    {
        float fxi, derivativei, x = (float)i * h;
        fxi = f(x);
        derivativei = (f(x - h) - f(x + h)) / (2 * h);
        function_values[i][0] = x;
        function_values[i][1] = fxi;
        function_values[i][2] = derivativei;
        //printf("x =%f\tf(x)=%f\tf'(x)=%f\n", x, fxi, derivativei);
        fprintf(file, "x=%f\tf(x)=%f\tf'(x)=%f\n", x, fxi, derivativei);
    }
}