#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define S_BOUNDARY 90
#define L_BOUNDARY 100

int main(void) {
    int chest;
    char size;

    printf("�����ѷ��� �Է��ϼ���: ");
    scanf("%d", &chest);

    if (chest >= L_BOUNDARY) {
        size = 'L';
    }
    else if (chest >= S_BOUNDARY) {
        size = 'M';
    }
    else {
        size = 'S';
    }

    printf("������� %c �Դϴ�.\n", size);

    return 0;
}
