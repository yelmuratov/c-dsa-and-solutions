#include <stdio.h>

int PrintMenu(void) {
    int option;
    printf("\nChoose an option:\n");
    printf("  1) Tip calculator\n");
    printf("  2) Split bill\n");
    printf("  0) Exit\n");
    printf("> ");
    if (scanf("%i", &option) != 1) {
        while (getchar() != '\n');  
        return -1;
    }
    return option;
}

int TipCalculator(double bill, float tip_percent, double *tip) {
    if (tip_percent < 0) {
        return 0;
    }
    *tip = bill * tip_percent / 100;
    return 1;
}

double BillSplitter(double bill, int PersonCount) {
    return bill / PersonCount;
}

int main(void) {
    printf("Welcome to TIP & Bill calculator!\n");

    while (1) {
        int option = PrintMenu();

        if (option == 0) {
            printf("Goodbye!\n");
            break;
        }

        switch (option) {
        case 1: {
            double bill, tip;
            float tip_percent;

            printf("Enter the bill amount: ");
            scanf("%lf", &bill);

            printf("Enter the tip percentage: ");
            scanf("%f", &tip_percent);

            if (TipCalculator(bill, tip_percent, &tip) != 1) {
                printf("Wrong tip percentage entered\n");
                break;
            }

            printf("Calculated tip: %.2f\n", tip);
            printf("Total:          %.2f\n", bill + tip);
        }
        break;

        case 2: {
            double bill;
            int people;

            printf("Enter the bill amount: ");
            scanf("%lf", &bill);

            printf("Enter number of people: ");
            scanf("%i", &people);

            if (people <= 0) {
                printf("Number of people must be at least 1\n");
                break;
            }

            printf("Each person pays: %.2f\n", BillSplitter(bill, people));
        }
        break;

        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}