#include <stdio.h>

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
}

// Function to perform modulus division
int moddivision(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
}

int main() {
    double num1, num2;
    int intNum1, intNum2;
    int choice;

    printf("Welcome to the simple calculator!\n");

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus Division (%%)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the calculator. Thank you!\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                printf("Result: %.2lf\n", add(num1, num2));
                break;
            case 2:
                printf("Result: %.2lf\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result: %.2lf\n", multiply(num1, num2));
                break;
            case 4:
                printf("Result: %.2lf\n", divide(num1, num2));
                break;
            case 5:
                intNum1 = (int)num1;
                intNum2 = (int)num2;
                printf("Result: %d\n", moddivision(intNum1, intNum2));
                break;
            default:
                printf("Invalid choice. Please select a valid operation.\n");
        }
    }

    return 0;
}

