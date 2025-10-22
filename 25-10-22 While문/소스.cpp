#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int calculate_gcd_while(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Enter the first integer: ");
    if (scanf("%d", &num1) != 1) return 1;

    printf("Enter the second integer: ");
    if (scanf("%d", &num2) != 1) return 1;

    if (num1 == 0 || num2 == 0) {
        printf("GCD: %d\n", abs(num1) + abs(num2));
        printf("LCM: 0\n");
        return 0;
    }

    int gcd_result = calculate_gcd_while(num1, num2);

    long long lcm_result = (long long)num1 / gcd_result * num2;

    printf("\n--- Results (while loop) ---\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    printf("GCD (Greatest Common Divisor): %d\n", gcd_result);
    printf("LCM (Least Common Multiple): %lld\n", lcm_result);

    return 0;
}