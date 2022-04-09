#include <stdio.h>
#include <math.h>

double V(double L, double m, double r)
{
    return(pow(L,2)*((1/(2*pow(r,2))) - (m/pow(r,3))));
}

/*dI1/dt = -4*I1+3*I2+6 = f1(x,y)*/
double R(double t, double r, double phi)
{
    return(sqrt(2*0.46 - 2*V(5,1,r)));
}

/*dy2/dx = 0.6*f1(t,I1,I2)-0.2*I2 = f2(x,y)*/
double Phi(double t, double r,double phi)
{
    return(5/sqrt(2*0.4-2*V(5,1,r)));
}


int main()
{
    
    int i, j, N;
    double t0, r0, phi0, a, b, h, x, y, k11, k21, k31, k41, k12, k22, k32, k42;
    printf("Type the value of a and b:\n");
    scanf("%lf%lf", &a, &b);
    printf("Type the value of N:\n");
    scanf("%d", &N);
    printf("Type the value of t0, r0(t0) and phi(t0):\n");
    scanf("%lf%lf%lf", &t0, &r0, &phi0);
    h = (b-a)/N;
    
    printf("h=%f\n", h);
    printf(" ");
    printf("at t=%f\t, r=%f\t, phi=%f\n", t0, r0*cos(phi0), r0*sin(phi0));
    
    for (i=0; i <= N; i++)
    {
        for (j=1; j<=2; j++)
        {
            if (j == 1)
            {
                k11 = h*R(t0,r0,phi0);
            }
            else
            {
                k12 = h*Phi(t0,r0,phi0);
            }
        }
        
        for (j=1; j<=2; j++)
        {
            if (j == 1)
            {
                k21 = h*R(t0 + h/2, r0 + k11/2, phi0 + k12/2);
            }
            else
            {
                k22 = h*Phi(t0 + h/2, r0 + k11/2, phi0 + k12/2);
            }
        }
        
        for (j=1; j<=2; j++)
        {
            if (j == 1)
            {
                k31 = h*R(t0 + h/2, r0 + k21/2, phi0 + k22/2);
            }
            else
            {
                k32 = h*Phi(t0 + h/2, r0 + k21/2, phi0 + k22/2);
            }
        }
        
        for (j=1; j<=2; j++)
        {
            if (j == 1)
            {
                k41 = h*R(t0 + h/2, r0 + k31/2, phi0 + k32/2);
            }
            else
            {
                k42 = h*Phi(t0 + h/2, r0 + k31/2, phi0 + k32/2);
            }

        }
        t0 = t0 + h;
        r0 = r0 + (k11 + 2*k21 + 2*k31 + k41)/6;
        phi0 = phi0 + (k12 + 2*k22 + 2*k32 + k42)/6;

        x = r0*cos(phi0);
        y = r0*sin(phi0);

        printf("at t=%f\t, x=%f\t, y=%f\n", t0, x, y);

    }

    return 0;  
        
}

