#include <stdio.h>

double add2(double a, double b){
    return a+b;
}

double subtract2(double a, double b){
    return a - b;
}

double multiply2(double a, double b){
    return a * b;
}

int divide2(double a, double b, double *r){
    if(b==0) return 1;
    *r = a / b;
    return 0;
}

void askNumbers(double *a, double *b){
    printf("Enter the first number:");
    scanf("%lf",a);
    printf("Enter the second number: ");
    scanf("%lf",b);
}

int main()
{
    printf("Welcom to the world's best calculato ever :) \n");

    printf("1) add \n");
    printf("2) subtract \n");
    printf("3) multiply \n");
    printf("4) divide \n");

    printf("Chose an operator: \n");

    int option; 
    double a,b; 

    scanf("%i", &option);
    askNumbers(&a,&b);

    switch(option){
        case 1:
            printf("Result = %f\n", add2(a, b));
            break;
        case 2: 
            printf("Result = %f\n", subtract2(a,b));
            break;
        case 3:
            printf("Result = %f\n", multiply2(a,b));
            break;
        case 4:{
            double r;
            if(divide2(a,b,&r) != 0)
                printf("ha, ha. U think I am crazy? U cannot divide by zero");
            else
                printf("Result = %f\n",r);
            break;
        }
        default:
            printf("Operator not found \n");
    }
    return 0;
}