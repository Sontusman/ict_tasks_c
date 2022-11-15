//Строганова С., 105
//Задача 4.1

//exp(-x^2) + 2 = x
//метод итераций

#include <stdio.h>
#include <math.h>

//функция (свою вставить)
double equation(double x){
    return exp(-1*pow(x,2))+2;
}
//реализация самого метода
double grad_down(double x, double accuracy, double error)
{   
    int num_iterations=0;
    while (abs(x-equation(x))>=accuracy){
        x=equation(x);
        num_iterations+=1;
        //if (num_iterations<=10){printf("%d\n%f\n%f\n", num_iterations, abs(x-equation(x)));}
        //if (current_accuracy > accuracy)||(current_error > error){break;}
    //return x, num_iterations, current_accuracy, current_error;
    }
    printf("Solution: %f;\n Number of iterations: %d;\n Error and Accuracy:%f\n", equation(x), num_iterations, abs(x-equation(x)));
}

int main()
{
    //asking questions
    double start_x, accuracy, error;
    printf("Enter first point: \n");
    scanf("%lf", &start_x);
    printf("Enter required accuracy: \n");
    scanf("%lf", &accuracy);
    printf("Enter required error: \n");
    scanf("%lf", &error);
    grad_down(start_x, accuracy, error);
    return 0;
}