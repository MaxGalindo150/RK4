#include <stdio.h>
#include <math.h>

/*dy/dx = x-y = f(x,y)*/
float f(float x, float y)
{
    return(y - x*x +1);
}

int main()
{
    int i, N;
    float x0, y0, a, b, h, k1, k2, k3, k4;
    printf("Type the value of a and b:\n");
    scanf("%f%f", &a, &b);
    printf("Type the value of N:\n");
    scanf("%d", &N);
    printf("Type the value of x0 and y0(x0):\n");
    scanf("%f%f", &x0, &y0);
    h = (b-a)/N;
    printf("h=%f\n", h);
    printf(" ");
    printf("at x=%f\t, y=%f\t", x0, y0);
    for (i=0; i <= N; i++)
    {
        k1 = h*f(x0,y0);
        k2 = h*f(x0 + h/2, y0 + k1/2);
        k3 = h*f(x0 + h/2, y0 + k2/2);
        k4 = h*f(x0 + h, y0 + k3);
        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 = x0 + h;
        printf("at x=%f\t, y=%f\n", x0, y0);
    }

    return 0;  
}