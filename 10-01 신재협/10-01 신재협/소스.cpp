#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disacle:4996)
#include <stdio.h>

int main(void)
{
    // 1: ���� ����(�̸�, �й�, Ű, ������, BMI)
    char name[20];
    int studentID;
    double height_cm, weight_kg, bmi;

    // 2: scanf �Ǵ� scanf_s�� �� ������ �� �ٷ� �Է� �ޱ�
    printf("�̸�, �й�, Ű(cm), ������(kg)�� �Է��ϼ��� (��: ȫ�浿 20231234 175.5 70.2): \n");
    scanf_s("%s %d %lf %lf", name, (int)sizeof(name), &studentID, &height_cm, &weight_kg);

    // 3: ������ BMI ���
    // (BMI = ������(kg) / (Ű(m) * Ű(m)) ������ ����մϴ�.)
    double height_m = height_cm / 100.0;
    bmi = weight_kg / (height_m * height_m);

    // 4-1: ������(�̸�, �й�, Ű, ������)
    printf("\n--- �Է� ���� ---\n");
    printf("�̸�: %s\n", name);
    printf("�й�: %d\n", studentID);
    printf("Ű: %.1lf cm\n", height_cm);
    printf("������: %.1lf kg\n", weight_kg);

    // 4-2: ������(BMI)
    printf("BMI: %.2lf\n", bmi);
    printf("-----------------\n");

    return 0;
}
