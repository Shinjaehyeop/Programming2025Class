#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ���� ���: 20�� �̸�/�̻�
#define AGE_STANDARD 20

// �����ѷ� ���� ���
#define CHEST_UNDER20_S 85 // 20�� �̸� S ��� (85 �̸� S, 85 �̻� M)
#define CHEST_UNDER20_M 95 // 20�� �̸� M ��� (95 �̻� L)

#define CHEST_OVER20_S 90 // 20�� �̻� S ��� (90 �̸� S, 90 �̻� M)
#define CHEST_OVER20_M 100 // 20�� �̻� M ��� (100 �̻� L)

int main(void) {
    int age, chest;
    char size;

    printf("���̿� �����ѷ��� �Է��ϼ��� (��: 25 95): ");
    scanf("%d %d", &age, &chest); // ���̿� �����ѷ��� �� ���� �Է¹޽��ϴ�.

    // 1. ���̸� �������� ũ�� �б��մϴ�.
    if (age < AGE_STANDARD) {
        // 20�� �̸��� ��: 85, 95�� �������� ������ ����
        if (chest < CHEST_UNDER20_S) {
            size = 'S';
        }
        else if (chest < CHEST_UNDER20_M) {
            size = 'M';
        }
        else {
            size = 'L';
        }
    }
    else {
        // 20�� �̻��� ��: 90, 100�� �������� ������ ����
        if (chest < CHEST_OVER20_S) {
            size = 'S';
        }
        else if (chest < CHEST_OVER20_M) {
            size = 'M';
        }
        else {
            size = 'L';
        }
    }

    printf("������� %c �Դϴ�.\n", size);

    return 0;
}
