#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>

void setcolor(int color);
double evaluate(char equation[]);
void display(double result);

int main()
{
    char equation[100]; // Array to hold the equation string
    double result;

    printf("Welcome to the calculator!\n");
    while (true)
    {
    
        printf("\nEnter an equation ('a + b', 'a - b', 'a * b', 'a / b', 'a %% b', 'a ^ b'):\n");
        printf("Type 'exit' to quit.\n");
        printf("\nEnter equation: ");
        fgets(equation, sizeof(equation), stdin);

        // Remove newline character from fgets input
        if (equation[strlen(equation) - 1] == '\n')
            equation[strlen(equation) - 1] = '\0';

        // Check for exit condition
        if (strcmp(equation, "exit") == 0)
        {
            printf("Exiting the calculator. Thank you!\n");
            break;
        }

        // Evaluate the equation and display the result
        result = evaluate(equation);
        display(result);
    }

    return 0;
}

void setcolor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

double evaluate(char equation[])
{
    double result = 0.0;
    char operator;
    double operand1, operand2;

    // Scan the equation string to extract operands and operator
    int scanned = sscanf(equation, "%lf %c %lf", &operand1, &operator, &operand2);

    // Check if sscanf successfully scanned 3 items
    if (scanned != 3)
    {
        printf("Invalid input format. Please use 'a operator b'.\n");
        return 0.0;
    }

    // Perform the calculation based on the operator
    switch (operator)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        if (operand2 != 0)
            result = operand1 / operand2;
        else
        {
            setcolor(12); // Red color for error
            printf("Error: Division by zero is not allowed.\n");
            return 0.0;
        }
        break;
    case '%':
        if (operand2 != 0)
            result = fmod(operand1, operand2); // fmod for floating-point modulus
        else
        {
            setcolor(12); // Red color for error
            printf("Error: Division by zero is not allowed.\n");
            return 0.0;
        }
        break;
    case '^':
        result = pow(operand1, operand2);
        break;
    default:
        setcolor(12); // Red color for error
        printf("Invalid operator '%c'. Please use one of '+', '-', '*', '/', '%%', '^'.\n", operator);
        return 0.0;
    }

    return result;
}

void display(double result)
{
    if (result >= 0)
        setcolor(10); // Green color for positive results
    else
        setcolor(12); // Red color for negative results

    printf("Result: %.2lf\n", result);
    setcolor(7); // Reset color to default (white)
}
