#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

double powerOfNumber(double base, int power){
    if(power == 0){
        return 1;
    }

    double sum = base;

    for (int i = 1; i < power; i++){
        sum*=base;
    }

    return sum;
}

double circleArea(double r){
    return M_PI * powerOfNumber(r,2);
}

double rectangleArea(double w, double h){
    return w * h;
}

double triangleArea(double h, double b){
    return (h * b)/2;
}

double bmi(double height, double weight){
    return weight/powerOfNumber(height,2);
}

int main(){
    printf("Welcome to the area and BMI calculator!\n");
    printf("Choose an option:\n");
    printf("  1) Circle area\n");
    printf("  2) Rectangle area\n");
    printf("  3) Triangle area\n");
    printf("  4) BMI\n");
    printf("> ");

    int option;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    double a, b;

    switch (option) {
        case 1:
            printf("Radius: ");
            scanf("%lf", &a);
            printf("Circle area: %.2f\n", circleArea(a));
            break;

        case 2:
            printf("Width: ");
            scanf("%lf", &a);
            printf("Height: ");
            scanf("%lf", &b);
            printf("Rectangle area: %.2f\n", rectangleArea(a, b));
            break;

        case 3:
            printf("Base: ");
            scanf("%lf", &a);
            printf("Height: ");
            scanf("%lf", &b);
            printf("Triangle area: %.2f\n", triangleArea(b, a));
            break;

        case 4:
            printf("Height (m): ");
            scanf("%lf", &a);
            printf("Weight (kg): ");
            scanf("%lf", &b);
            printf("BMI: %.1f\n", bmi(a, b));
            break;

        default:
            printf("Unknown option: %d\n", option);
            break;
    }

    return 0;
}