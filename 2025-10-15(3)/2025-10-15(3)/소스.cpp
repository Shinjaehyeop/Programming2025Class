#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num1, num2;
    char op;

    printf("������ �Է��ϼ��� (��: 10-6, 11/3): ");
    scanf("%d%c%d", &num1, &op, &num2);

    switch (op) {
    case '+':
        printf("���: %d\n", num1 + num2);
        break;
    case '-':
        printf("���: %d\n", num1 - num2);
        break;
    case '*':
        printf("���: %d\n", num1 * num2);
        break;
    case '/':
        if (num2 == 0) {
            printf("����: 0���� ���� �� �����ϴ�.\n");
        }
        else {
            printf("���: %d\n", num1 / num2);
        }
        break;
    default:
        printf("����: �� �� ���� �������Դϴ�.\n");
        break;
    }

    return 0;
}
