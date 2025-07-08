#include <math.h>
#include <stdio.h>

const double PI = 3.141592654;

// maths incorrect
double cylinderVolume(double radius, double height)
{
    double volume = PI*pow(radius, 2.0)*height;
    return volume;
}

// maths incorrect
double sphereVolume(double radius)
{
    double volume = 4.0*PI*pow(radius, 3.0)/3.0;
    return volume;
}

double recursiveCalculator(char userSelection)
{
    double volumeOfShape = -1;

    if (userSelection == 'z')
    {
        // invoke overloaded function
        double r, h;
        printf("Radius of Cylinder: ");
        scanf("%lf", &r);
        printf("Height of Cylinder: ");
        scanf("%lf", &h);
        volumeOfShape = cylinderVolume(r, h);
    }
    else if (userSelection == 'c')
    {
        // invoke original function
        double r;
        printf("Radius of Sphere: ");
        scanf("%lf", &r);
        volumeOfShape = sphereVolume(r);
    }
    else
    {
        // recursion
        printf("Incorrect Choice.\n");
        printf("Enter z for cylinder, c for circle: ");
        scanf("%c", &userSelection);
        volumeOfShape = recursiveCalculator(userSelection);
    }
    return volumeOfShape;
}



int main()
{
    char userSelection;
    printf("Enter z for cylinder, c for circle: ");
    scanf("%c", &userSelection);
    double answer = recursiveCalculator(userSelection);
    printf("The volume is: %lf\n", answer);
    return 0;
}

/* 
    linux command to compile
    gcc 2025.07.05_calculations.c -o calculations -lm
*/