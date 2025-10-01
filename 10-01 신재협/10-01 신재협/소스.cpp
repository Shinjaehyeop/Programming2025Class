#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disacle:4996)
#include <stdio.h>

int main(void)
{
    // 1: 변수 선언(이름, 학번, 키, 몸무게, BMI)
    char name[20];
    int studentID;
    double height_cm, weight_kg, bmi;

    // 2: scanf 또는 scanf_s로 위 정보를 한 줄로 입력 받기
    printf("이름, 학번, 키(cm), 몸무게(kg)를 입력하세요 (예: 홍길동 20231234 175.5 70.2): \n");
    scanf_s("%s %d %lf %lf", name, (int)sizeof(name), &studentID, &height_cm, &weight_kg);

    // 3: 간단한 BMI 계산
    // (BMI = 몸무게(kg) / (키(m) * 키(m)) 공식을 사용합니다.)
    double height_m = height_cm / 100.0;
    bmi = weight_kg / (height_m * height_m);

    // 4-1: 결과출력(이름, 학번, 키, 몸무게)
    printf("\n--- 입력 정보 ---\n");
    printf("이름: %s\n", name);
    printf("학번: %d\n", studentID);
    printf("키: %.1lf cm\n", height_cm);
    printf("몸무게: %.1lf kg\n", weight_kg);

    // 4-2: 결과출력(BMI)
    printf("BMI: %.2lf\n", bmi);
    printf("-----------------\n");

    return 0;
}
