#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


double function(double t, double y)
{
    double temp;
    temp = y + pow(t, 2) - 1;
    return temp;
}

double euler(double t, double y, double dt, double functions(double, double))
{
    double output;
    double func_i;
    func_i = functions(t, y);
    output = y + dt * func_i;
    return output;
}

int main()
{
    FILE *output;
    output = fopen("du_3.txt", "w");
    double tmax, dt, t = 0;
    scanf("%lf %lf", &tmax, &dt);
    int steps = (int) tmax / dt;
    float y_euler = 1.0;
    for (int i = 0; i < steps - 1; i++)
    {
        y_euler = euler(t, y_euler, dt, function);
        fprintf(output, "%f %f \n", t, y_euler);
        t = t + dt;
    }
}
