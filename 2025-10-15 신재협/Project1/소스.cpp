#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define S_BOUNDARY 90
#define L_BOUNDARY 100

int main(void) {
    int chest;
    char size;

    printf("가슴둘레를 입력하세요: ");
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

    printf("사이즈는 %c 입니다.\n", size);

    return 0;
}
