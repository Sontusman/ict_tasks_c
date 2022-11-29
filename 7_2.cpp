// Строганова Софья, 105
// Задание 7.2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct dot
{
    int x, y;
};

struct line
{
    struct dot d1, d2;
};

struct circle
{
    struct dot center;
    int radius;
};

struct rectangle
{
    struct dot d1, d2;
};

void draw_line(int d1, int d2, int d3, int d4,  char plane[20][85])
{
    float dx = d3-d1;
    float dy = d4-d2;
    int m=0;
    if (dy>dx){
        m = (int) dy;
    }
    else{
        m = (int) dx;
    }
    m = abs(m);
    float len = pow(pow(dx, 2)+pow(dy, 2), 0.5);
    dx = dx*1/len;
    dy = dy*1/len;
    for (int i=0; i<m; i++){
        plane[d1 + (int)(i*dx)][d2 + (int)(i*dy)]='#';
    }
}

void draw_circle(int d1, int d2, int d3, char plane[20][85]){
    for(int i = d1-d3; i<=d1+d3; i++){
        for (int g= d2-d3; g<=d2+d3; g++){
            printf("%d %d\n", i, g);
            if (pow(pow(abs(i-d1), 2) + pow(abs(g-d2), 2), 0.5)<= d3){
                plane[i][g] = '#';
            }
        }
    }
}


void draw_rectangle(int d1, int d2, int d3, int d4, char plane[20][85])
{
    for (int i = d1; i <= d3; i++)
    {
        for (int j = d2; j <= d4; j++)
        {
            if ((i == d1) || (i == d3) || (j == d2) || (j == d4))
            {
                plane[i][j] = '#';
            }
        }
    }
}

void draw(char plane[20][85], FILE *file)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 85; j++)
        {
            printf("%c", plane[i][j]);
            fprintf(file, "%c", plane[i][j]);
        }
        printf("\n");
        fprintf(file, "\n");
    }
}

int main()
{
    FILE *input;
    FILE *output;
    input = fopen("7_2i.txt", "r");
    output = fopen("7_2o.txt", "w");
    char plane[20][85];
    memset(plane, ' ', sizeof(plane[0][0]) * 20 * 85);
    char str[256];
    struct dot dots[256];
    while (fgets(str, 256, input) != NULL)
    {
        char ch;
        printf("%s", str);
        int d1, d2, d3, d4;
        sscanf(str, "%c %i %i %i %i", &ch, &d1, &d2, &d3, &d4);
        if (ch == 'd')
        {
            plane[d1][d2] = '#';
        }
        else if (ch == 'l')
        {   
            draw_line(d1, d2, d3, d4, plane);
        }
        else if (ch == 'r')
        {
            draw_rectangle(d1, d2, d3, d4, plane);
        }
        else if (ch = 'e')
        {
            draw_circle(d1, d2, d3, plane);
        }
    }
    draw(plane, output);
    fclose(input);
    fclose(output);
}