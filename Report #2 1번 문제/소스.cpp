#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 600

int main(void)
{
    double weight;

    printf("������������ �� ����(kg)�� �Է��ϼ���: ");
    scanf("%lf", &weight);

    if (weight < 0) {
        printf("invalid input\n");
        return 1;
    }

    printf("��� (if�� ���): ");
    if (weight <= MAX_WEIGHT) {
        printf("OK\n");
    }
    else {
        printf("Overload\n");
    }

    printf("��� (���� ������ ���): ");
    printf("%s\n", (weight <= MAX_WEIGHT) ? "OK" : "Overload");

    return 0;
}
