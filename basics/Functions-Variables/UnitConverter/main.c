#include <stdio.h>

int PrintMenu(void) {
    int option;
    printf("\nChoose an option:\n");
    printf("  1) Miles -> Kilometers\n");
    printf("  2) Kilometers -> Miles\n");
    printf("  3) Pounds -> Kilograms\n");
    printf("  4) Kilograms -> Pounds\n");
    printf("  0) Exit\n");
    printf("> ");
    if (scanf("%i", &option) != 1) {
        while (getchar() != '\n');
        return -1;
    }
    return option;
}

double mileToKM(double mile) {
    return mile / 0.621371;
}

double kmToMile(double km) {
    return km * 0.621371;
}

double poundToKg(double pound) {
    return pound / 2.20462;
}

double kgToPound(double kg) {
    return kg * 2.20462;
}

int main(void) {
    printf("Welcome to Unit converter!\n");

    while (1) {
        int option = PrintMenu();

        if (option == 0) {
            printf("Goodbye!\n");
            break;
        }

        double value;

        switch (option) {
        case 1:
            printf("Enter miles: ");
            scanf("%lf", &value);
            printf("%.2f miles = %.2f km\n", value, mileToKM(value));
            break;

        case 2:
            printf("Enter kilometers: ");
            scanf("%lf", &value);
            printf("%.2f km = %.2f miles\n", value, kmToMile(value));
            break;

        case 3:
            printf("Enter pounds: ");
            scanf("%lf", &value);
            printf("%.2f lb = %.2f kg\n", value, poundToKg(value));
            break;

        case 4:
            printf("Enter kilograms: ");
            scanf("%lf", &value);
            printf("%.2f kg = %.2f lb\n", value, kgToPound(value));
            break;

        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}