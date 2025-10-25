#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // return 1; ���

int main(void)
{
    int door_status;
    double temperature;
    int duration;

    printf("�� ���� (0: ����, 1: ����): ");
    scanf("%d", &door_status);

    // �� ���� �Է°� ��ȿ�� �˻�
    if (door_status != 0 && door_status != 1) {
        printf("invalid input\n");
        return 1;
    }

    printf("���� �µ� (C): ");
    scanf("%lf", &temperature);

    // �� ���¿� ���� �ð� �Է� ������Ʈ ���� �� �Է�
    if (door_status == 1) {
        printf("���� ���� �ִ� �ð� (��): ");
    }
    else { // door_status == 0
        printf("���� �µ��� ������ �ð� (��, ���� ���� ��� ��츸 �ش�): ");
    }
    scanf("%d", &duration);

    // �ð� �Է°� ��ȿ�� �˻�
    if (duration < 0) {
        printf("invalid input\n");
        return 1;
    }

    printf("����� ����: ");

    // ���� �Ǻ� ���� ����
    if (door_status == 0) { // ���� ���� ���� ��
        if (temperature >= 2.0 && temperature <= 8.0) {
            printf("Normal\n");
        }
        else { // �µ��� ���� ������ ����� ��
            if (duration <= 30) {
                printf("Warning\n");
            }
            else {
                printf("Critical\n");
            }
        }
    }
    else { // ���� ���� ���� �� (door_status == 1)
        if (duration >= 60 && (temperature < 2.0 || temperature > 8.0)) {
            printf("Critical\n");
        }
        else {
            // �������� ��õ��� ���� '�� ���� + Critical �ƴ� ����'�� Normal�� ó��
            printf("Normal\n");
        }
    }

    return 0; // ���� ����
}
