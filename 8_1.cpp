#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

double* function(double t, double *x, int n)
{
    double *temp = (double*)malloc(n * sizeof(double));
    temp[0] = -x[0] + x[1] - x[2] + x[3];
    temp[1] = -x[0] + x[2] - x[3];
    temp[2] = x[0] - x[1] + x[3] + 0.1 * t;
    temp[3] = x[0] - x[3] - 0.1 * t;
    return temp;
}

double* euler(double t, double *x, double dt, int n, double* functions(double, double*, int))
{
    double *output = (double*)malloc(n * sizeof(double));
    double *func_i = (double*)malloc(n * sizeof(double));
    func_i = functions(t, x, n);
    for (int i = 0; i < n; i++)
    {
        output[i] = x[i] + dt * func_i[i];
    }
    return output;
}

double* runge_kutta(double t, double *x, double dt, int n, double* functions(double, double*, int))
{
    double *output = (double*)malloc(n * sizeof(double));
    double *func_i0 = (double*)malloc(n * sizeof(double));
    func_i0 = functions(t, x, n);
    double *func_i1 = (double*)malloc(n * sizeof(double));
    double *func_i2 = (double*)malloc(n * sizeof(double));
    double *func_i3 = (double*)malloc(n * sizeof(double));
    double k0[4], k1[4], k2[4], k3[4], x0[4];
    for (int i = 0; i < n; i++)
    {
        k0[i] = dt * func_i0[i];
        x0[i] = x[i] + k0[i];
    }
    func_i1 = functions(t + 0.5 * dt, x0, n);
    for (int i = 0; i < n; i++)
    {
        k1[i] = dt * func_i1[i];
        x0[i] = x[i] + 0.5 * k1[i];
    }
    func_i2 = functions(t + 0.5 * dt, x0, n);
    for (int i = 0; i < n; i++)
    {
        k2[i] = dt * func_i2[i];
        x0[i] = x[i] + 0.5*k2[i];
    }
    func_i3 = functions(t + dt, x0, n);
    for (int i = 0; i < n; i++)
    {
        k3[i] = dt * func_i3[i];
    }
    for (int i = 0; i < n; i ++)
    {
        output[i] = x[i]+(k0[i] + 2*k1[i] + 2*k2[i] + k3[i]) / 6.0;
    }
    return output;
}

void print_values(double t, double *x, int n, char ch, FILE *file)
{
    double sum = x[0] + x[1] + x[2] + x[3];
    fprintf(file, "%c %lf %lf %lf %lf %lf %lf   ", ch, x[0], x[1], x[2], x[3], t, sum);
}

int main()
{
    FILE *output;
    output = fopen("8o.txt", "w");
    double tmax, dt, t = 0;
    scanf("%lf %lf", &tmax, &dt);
    int n = 4, steps = (int) tmax / dt;
    double x_e[4];
    double x_r[4];
    double *y_euler = (double*)malloc(n * sizeof(double));
    double *y_runge_kutta = (double*)malloc(n * sizeof(double));
    x_e[0] = 0.1;
    x_e[1] = -0.1;
    x_e[2] = 0.1;
    x_e[3] = -0.1;
    x_r[0] = 0.1;
    x_r[1] = -0.1;
    x_r[2] = 0.1;
    x_r[3] = -0.1;
    for (int i = 0; i < steps - 1; i++)
    {
        y_euler = euler(t, x_e, dt, n, function);
        y_runge_kutta = runge_kutta(t, x_r, dt, n, function);
        print_values(t, y_euler, n, 'e', output);
        print_values(t, y_runge_kutta, n, 'r', output);
        fprintf(output, "\n");
        t = t + dt;
        x_e[0] = y_euler[0];
        x_e[1] = y_euler[1];
        x_e[2] = y_euler[2];
        x_e[3] = y_euler[3];
        x_r[0] = y_runge_kutta[0];
        x_r[1] = y_runge_kutta[1];
        x_r[2] = y_runge_kutta[2];
        x_r[3] = y_runge_kutta[3];
    }
}