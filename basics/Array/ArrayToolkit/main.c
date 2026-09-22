#include <stdio.h>
#include <stdbool.h>

void reverse_array(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

bool contain_check(const int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int count_occurance(const int arr[], int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int summ_array(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i + 1, arr[i]);
    }
}

void print_menu(void) {
    printf("\n===== Array Toolkit =====\n");
    printf("1. Print array\n");
    printf("2. Reverse array\n");
    printf("3. Check if value exists\n");
    printf("4. Count occurrences of value\n");
    printf("5. Sum of array\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    int n;
    printf("Enter the array size n = ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Your array is ready:\n");
    print_array(arr, n);

    int choice;
    int value;

    do {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a number.\n");
            clear_input();
            choice = -1;   
            continue;
        }

        switch (choice) {
            case 1:
                print_array(arr, n);
                break;

            case 2:
                reverse_array(arr, n);
                printf("Array reversed:\n");
                print_array(arr, n);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (contain_check(arr, n, value)) {
                    printf("%d is in the array.\n", value);
                } else {
                    printf("%d is NOT in the array.\n", value);
                }
                break;

            case 4:
                printf("Enter value to count: ");
                scanf("%d", &value);
                printf("%d appears %d time(s).\n",
                       value, count_occurance(arr, n, value));
                break;

            case 5:
                printf("Sum = %d\n", summ_array(arr, n));
                break;

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option, try again.\n");
        }
    } while (choice != 0);

    return 0;
}