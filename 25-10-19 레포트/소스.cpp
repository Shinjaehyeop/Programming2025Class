#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num1, num2;
    int isGreater;
    int isAllPositive;

    printf("�� ���� ������ ����� �����Ͽ� �Է��ϼ���: ");
    scanf("%d %d", &num1, &num2);

    printf("\n--- ���� ��� ---\n");

    isGreater = (num1 > num2);
    printf("1. ���� ���� ���: ù ��° ���ڰ� �� ��° ���ں��� Ů�ϱ�? (1=��, 0=����) -> %d\n", isGreater);

    isAllPositive = (num1 > 0 && num2 > 0);
    printf("2. �� ���� ���: �� ���� ��� ����Դϱ�? (1=��, 0=����) -> %d\n", isAllPositive);

    printf("3. ���� ���� �� ù ��° ����: %d\n", num1);
    num1++;
    printf("   ���� ���� �� ù ��° ����: %d\n", num1);

    return 0;