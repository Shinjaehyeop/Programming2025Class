#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 나이 기준 상수: 20세 미만/이상
#define AGE_STANDARD 20

// 가슴둘레 기준 상수
#define CHEST_UNDER20_S 85 // 20세 미만 S 경계 (85 미만 S, 85 이상 M)
#define CHEST_UNDER20_M 95 // 20세 미만 M 경계 (95 이상 L)

#define CHEST_OVER20_S 90 // 20세 이상 S 경계 (90 미만 S, 90 이상 M)
#define CHEST_OVER20_M 100 // 20세 이상 M 경계 (100 이상 L)

int main(void) {
    int age, chest;
    char size;

    printf("나이와 가슴둘레를 입력하세요 (예: 25 95): ");
    scanf("%d %d", &age, &chest); // 나이와 가슴둘레를 한 번에 입력받습니다.

    // 1. 나이를 기준으로 크게 분기합니다.
    if (age < AGE_STANDARD) {
        // 20세 미만일 때: 85, 95를 기준으로 사이즈 결정
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
        // 20세 이상일 때: 90, 100을 기준으로 사이즈 결정
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

    printf("사이즈는 %c 입니다.\n", size);

    return 0;
}
