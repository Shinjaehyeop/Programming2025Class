#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 600

int main(void)
{
    double weight;

    printf("엘리베이터의 총 하중(kg)을 입력하세요: ");
    scanf("%lf", &weight);

    if (weight < 0) {
        printf("invalid input\n");
        return 1;
    }

    printf("결과 (if문 사용): ");
    if (weight <= MAX_WEIGHT) {
        printf("OK\n");
    }
    else {
        printf("Overload\n");
    }

    printf("결과 (조건 연산자 사용): ");
    printf("%s\n", (weight <= MAX_WEIGHT) ? "OK" : "Overload");

    return 0;
}
