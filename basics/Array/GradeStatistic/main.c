#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_grades(int array[], int size){
    for(int i = 0; i < size; i++){
        array[i] = rand() % 101;
    }
}

void print_grades(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d) %d\n",i+1,array[i]);
    }
}

int find_max(int array[], int size){
    int max = array[0];

    for (int i = 1; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    return max;
}

int find_min(int array[], int size){
    int min = array[0];

    for (int i = 1; i < size; i++){
        if(array[i] < min){
            min = array[i];
        }
    }

    return min;
}

double find_sum(int array[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }

    return sum;
}

void print_menu(void) {
    printf("\n--- MENU ---\n");
    printf("1. Print all grades\n");
    printf("2. Highest grade\n");
    printf("3. Lowest grade\n");
    printf("4. Average grade\n");
    printf("5. Generate new grades\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

double calculate_average(int array[], int size){
    return find_sum(array,size)/size;
}

int main(){
    srand(time(NULL));

    int grades[10];
    int n = sizeof(grades) / sizeof(grades[0]);
    int choice;

    fill_grades(grades, n);

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_grades(grades, n);
                break;

            case 2:
                printf("Highest: %d\n", find_max(grades, n));
                break;

            case 3:
                printf("Lowest: %d\n", find_min(grades, n));
                break;

            case 4:
                printf("Average: %.2f\n", calculate_average(grades, n));
                break;

            case 5:
                fill_grades(grades, n);
                printf("New grades generated.\n");
                break;

            case 0:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}