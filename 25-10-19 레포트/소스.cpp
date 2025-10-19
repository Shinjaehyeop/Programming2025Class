#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num1, num2;
    int isGreater;
    int isAllPositive;

    printf("두 개의 정수를 띄어쓰기로 구분하여 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    printf("\n--- 연산 결과 ---\n");

    isGreater = (num1 > num2);
    printf("1. 관계 연산 결과: 첫 번째 숫자가 두 번째 숫자보다 큽니까? (1=참, 0=거짓) -> %d\n", isGreater);

    isAllPositive = (num1 > 0 && num2 > 0);
    printf("2. 논리 연산 결과: 두 숫자 모두 양수입니까? (1=참, 0=거짓) -> %d\n", isAllPositive);

    printf("3. 증감 연산 전 첫 번째 숫자: %d\n", num1);
    num1++;
    printf("   증감 연산 후 첫 번째 숫자: %d\n", num1);

    return 0;