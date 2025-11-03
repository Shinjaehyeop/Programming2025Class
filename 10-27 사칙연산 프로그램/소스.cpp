#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double calculate(double num1, char op, double num2);

int main(void)
{
    double num1, num2;
    char op;
    double result;

    printf("연산식 (예: 10 + 5)을 입력하세요: ");

    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
        return 1;
    }

    result = calculate(num1, op, num2);

    printf("\n결과: %.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);

    return 0;
}

double calculate(double num1, char op, double num2)
{
    double result = 0.0;

    switch (op) {
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
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            return 0.0;
        }
        break;
    case '%':
        result = (double)((int)num1 % (int)num2);
        break;
    default:
        return 0.0;
    }

    return result;
}
