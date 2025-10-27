#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // return 1; 사용

int main(void)
{
    int door_status;
    double temperature;
    int duration;

    printf("문 상태 (0: 닫힘, 1: 열림): ");
    scanf("%d", &door_status);

    // 문 상태 입력값 유효성 검사
    if (door_status != 0 && door_status != 1) {
        printf("invalid input\n");
        return 1;
    }

    printf("현재 온도 (C): ");
    scanf("%lf", &temperature);

    // 문 상태에 따라 시간 입력 프롬프트 변경 및 입력
    if (door_status == 1) {
        printf("문이 열려 있던 시간 (초): ");
    }
    else { // door_status == 0
        printf("현재 온도가 유지된 시간 (초, 정상 범위 벗어난 경우만 해당): ");
    }
    scanf("%d", &duration);

    // 시간 입력값 유효성 검사
    if (duration < 0) {
        printf("invalid input\n");
        return 1;
    }

    printf("냉장고 상태: ");

    // 상태 판별 로직 시작
    if (door_status == 0) { // 문이 닫혀 있을 때
        if (temperature >= 2.0 && temperature <= 8.0) {
            printf("Normal\n");
        }
        else { // 온도가 정상 범위를 벗어났을 때
            if (duration <= 30) {
                printf("Warning\n");
            }
            else {
                printf("Critical\n");
            }
        }
    }
    else { // 문이 열려 있을 때 (door_status == 1)
        if (duration >= 60 && (temperature < 2.0 || temperature > 8.0)) {
            printf("Critical\n");
        }
        else {
            // 문제에서 명시되지 않은 '문 열림 + Critical 아닌 상태'는 Normal로 처리
            printf("Normal\n");
        }
    }

    return 0; // 정상 종료
}
