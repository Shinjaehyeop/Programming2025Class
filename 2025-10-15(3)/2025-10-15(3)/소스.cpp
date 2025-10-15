#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num1, num2;
    char op;

    printf("수식을 입력하세요 (예: 10-6, 11/3): ");
    scanf("%d%c%d", &num1, &op, &num2);

    switch (op) {
    case '+':
        printf("결과: %d\n", num1 + num2);
        break;
    case '-':
        printf("결과: %d\n", num1 - num2);
        break;
    case '*':
        printf("결과: %d\n", num1 * num2);
        break;
    case '/':
        if (num2 == 0) {
            printf("오류: 0으로 나눌 수 없습니다.\n");
        }
        else {
            printf("결과: %d\n", num1 / num2);
        }
        break;
    default:
        printf("오류: 알 수 없는 연산자입니다.\n");
        break;
    }

    return 0;
}
