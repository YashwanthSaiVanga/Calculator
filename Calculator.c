#include <stdio.h>

void calculator() {
    double num1, num2, result;
    char operator;
    
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator! Please use +, -, *, or /.\n");
            return;
    }
    
    printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
}

int main() {
    calculator();
    return 0;
}