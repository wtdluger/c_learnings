#include <stdio.h>
#include <math.h>

const double PI = 3.141592654;

// this call results in a seg fault error
void circleCalculations(double radius, double *area, double *volume)
{
    *area = 4.0*PI*pow(radius, 2.0);
    *volume = 4.0*PI*pow(radius, 3.0)/3;
}


int main()
{
    double Radius = 0;
    double Area = 0;
    double Volume = 0;

    printf("What is the radius of the circle? ");
    scanf("%lf", &Radius);
    circleCalculations(Radius, &Area, &Volume);
    printf("The area is: %lf \n", Area);
    printf("The volume is: %lf \n", Volume);
    return 0;
}

/* 
    linux command to compile
    gcc 2025.07.05_calculations_with_void.c -o calculations_with_void -lm
*/