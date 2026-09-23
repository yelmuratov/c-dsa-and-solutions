#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool is_swapped = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                is_swapped = true;
            }
        }

        if(!is_swapped){
            break;
        }
    }
}

void selection_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){   
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            swap(&arr[i], &arr[min_index]);
        }
    }
}

bool is_sorted(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);             
    }
    printf("\n");
}

void fill_random(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 101;               
    }
}

void enter_numbers(int arr[], int n){
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++){
        printf("%d) ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void print_menu(void){
    printf("\n--- SORTING MENU ---\n");
    printf("1. Print array\n");
    printf("2. Generate random numbers\n");
    printf("3. Enter your own numbers\n");
    printf("4. Bubble sort\n");
    printf("5. Selection sort\n");
    printf("6. Check if sorted\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

int main(){
    srand(time(NULL));

    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    fill_random(arr, n);

    while(1){
        print_menu();

        if(scanf("%d", &choice) != 1){     
            while(getchar() != '\n');        
            printf("Please enter a number.\n");
            continue;
        }

        switch(choice){
            case 1:
                print_array(arr, n);
                break;

            case 2:
                fill_random(arr, n);
                printf("New random numbers generated.\n");
                print_array(arr, n);
                break;

            case 3:
                enter_numbers(arr, n);
                printf("Your numbers: ");
                print_array(arr, n);
                break;

            case 4:
                printf("Before: ");
                print_array(arr, n);
                bubble_sort(arr, n);
                printf("After bubble sort: ");
                print_array(arr, n);
                break;

            case 5:
                printf("Before: ");
                print_array(arr, n);
                selection_sort(arr, n);
                printf("After selection sort: ");
                print_array(arr, n);
                break;

            case 6:
                if(is_sorted(arr, n)){
                    printf("The array is sorted.\n");
                } else {
                    printf("The array is NOT sorted.\n");
                }
                break;

            case 0:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}