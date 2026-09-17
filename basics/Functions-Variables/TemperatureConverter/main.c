#include <stdio.h>

float celsius_to_fahrenheit(float c){
    float f = c * 9/5 + 32;

    return f;
};

float fahrenheit_to_celsius(float f){
    float c = (f-32)*5/9;

    return c;
};

int main(){
    printf("Welcome to temperature converter! \n");

    printf("Select the option \n");
    printf("1) Fahrenheit to celsius \n");
    printf("2) Celsius to fahrenheit \n");
    printf("Enter the option number:");

    int option;
    scanf("%i",&option);

    if(option == 1){
        float f;
        printf("Enter temperature in fahrenheit: ");
        scanf("%f",&f);

        float result = fahrenheit_to_celsius(f);

        printf("%f",result);
    }else if(option == 2){
        float c;
        printf("Enter temperature in celsius: ");
        scanf("%f",&c);

        float result = celsius_to_fahrenheit(c);

        printf("%f",result);
    }
}