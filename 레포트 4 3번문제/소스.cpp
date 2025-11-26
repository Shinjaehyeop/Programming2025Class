#define _CRT_SECURE_NO_WARNINGS // Visual Studio의 scanf 사용 경고 (C4996)를 무시하기 위해 추가
#include <stdio.h>
#include <stdlib.h> // exit 함수 사용

#define VEC_SIZE 3 // 3차원 벡터 크기 정의

// 3차원 벡터 성분을 입력받아 배열에 저장하는 함수 (Call by Reference)
void get_vector(double* v) {
    // 배열 주소(포인터)를 통해 입력받아 원본 배열에 저장
    printf("벡터 성분 3개를 입력하세요 (x y z): ");
    // 포인터 연산 v, v+1, v+2는 각 배열 요소의 주소
    if (scanf("%lf %lf %lf", v, v + 1, v + 2) != VEC_SIZE) {
        printf("입력 오류! 프로그램을 종료합니다.\n");
        exit(1);
    }
}

// 내적(Dot Product)을 계산하고 스칼라 값(double)을 반환하는 함수
double dot_product(double* a, double* b) {
    double result = 0.0;
    int i; // <--- C90 호환을 위해 변수 선언 위치 수정

    // 배열을 포인터로 받아 내적 계산 (Ax*Bx + Ay*By + Az*Bz)
    for (i = 0; i < VEC_SIZE; i++) { // 'int' 키워드 제거
        result += a[i] * b[i]; // 배열식으로 포인터 접근
    }
    return result; // 스칼라 값 반환
}

// 외적(Cross Product)을 계산하고 결과를 result 배열에 저장하는 함수 (Call by Reference)
void cross_product(double* a, double* b, double* result) {
    // result 포인터를 사용하여 결과 배열에 값 저장 (포인터 연산 활용)

    // Cx = Ay*Bz - Az*By
    *(result) = *(a + 1) * *(b + 2) - *(a + 2) * *(b + 1);

    // Cy = Az*Bx - Ax*Bz
    *(result + 1) = *(a + 2) * *(b)-*(a) * *(b + 2);

    // Cz = Ax*By - Ay*Bx
    *(result + 2) = *(a) * *(b + 1) - *(a + 1) * *(b);
}

int main(void) {
    double vector_a[VEC_SIZE];
    double vector_b[VEC_SIZE];
    double vector_c[VEC_SIZE]; // 외적 결과 저장 배열
    double dot_result;

    // 벡터 A의 성분을 입력받아 배열에 저장 (Call by Reference)
    printf("=== 벡터 A 입력 ===\n");
    get_vector(vector_a);

    // 벡터 B의 성분을 입력받아 배열에 저장 (Call by Reference)
    printf("=== 벡터 B 입력 ===\n");
    get_vector(vector_b);

    // 내적 계산 (함수 호출 및 값 저장)
    dot_result = dot_product(vector_a, vector_b);

    // 외적 계산 (함수 호출, 결과 배열의 주소를 전달하여 저장)
    cross_product(vector_a, vector_b, vector_c);

    // 결과 출력
    printf("\n--- 3차원 벡터 연산 결과 ---\n");
    printf("1. 내적 (A * B) : %.4lf\n", dot_result);
    printf("2. 외적 (A x B) : (%.4lf, %.4lf, %.4lf)\n",
        vector_c[0], vector_c[1], vector_c[2]);

    return 0;
}