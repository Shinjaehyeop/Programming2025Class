#define _CRT_SECURE_NO_WARNINGS // Visual Studio의 scanf 사용 경고 (C4996)를 무시하기 위해 추가
#include <stdio.h>
#include <stdlib.h> // 난수 생성 및 종료 함수를 사용
#include <time.h>   // 난수 시드 초기화를 위한 시간 함수 사용
#include <math.h>   // 표준편차 계산을 위한 제곱근(sqrt) 함수 사용

#define ARRAY_SIZE 100 // 전체 배열 크기 정의
#define SAMPLE_SIZE 10  // 추출할 데이터 개수 정의

// 통계량을 계산하는 함수 (배열 포인터와 결과 변수 주소를 사용)
// 매개변수: 배열의 시작 주소(arr_ptr)와 결과를 저장할 변수의 주소들
void calc_stats(int* arr_ptr, int start_idx, int end_idx,
    int* total_sum, double* variance, double* std_dev) {

    int i; // 반복문 제어 변수 선언 (C 표준 호환)
    int sum = 0;
    double mean = 0.0;
    double var_sum = 0.0;

    // 1. 총합 계산: 포인터 연산 *(arr_ptr + i)를 사용하여 배열 요소에 접근
    for (i = start_idx; i <= end_idx; i++) {
        sum += *(arr_ptr + i);
    }
    *total_sum = sum; // 총합 결과를 변수의 주소에 직접 저장 (Call by Reference)

    // 2. 평균 계산
    mean = (double)sum / SAMPLE_SIZE;

    // 3. 분산 계산 (각 데이터와 평균의 차이 제곱의 평균)
    for (i = start_idx; i <= end_idx; i++) {
        double diff = *(arr_ptr + i) - mean;
        var_sum += diff * diff;
    }
    *variance = var_sum / SAMPLE_SIZE; // 분산 결과를 주소에 저장

    // 4. 표준편차 계산: 분산 값에 제곱근 함수를 적용
    *std_dev = sqrt(*variance);
}

int main(void) {
    int data[ARRAY_SIZE]; // 100개 정수 배열 선언
    int i; // 반복문 제어 변수 선언
    int start_index, end_index;
    int total_sum;
    double variance, std_dev;

    srand(time(NULL)); // 현재 시간을 난수 시드로 사용

    // 난수 생성 및 배열에 저장 (반복문 for 사용)
    for (i = 0; i < ARRAY_SIZE; i++) {
        data[i] = (rand() % 100) + 1; // 1부터 100까지의 난수 생성
    }

    printf("시작 인덱스 (0~%d)와 끝 인덱스 (총 %d개)를 입력하세요 (예: 5 14): ", ARRAY_SIZE - SAMPLE_SIZE, SAMPLE_SIZE);

    // 사용자 입력 및 유효성 검사 (scanf 함수 사용)
    if (scanf("%d %d", &start_index, &end_index) != 2 ||
        end_index - start_index + 1 != SAMPLE_SIZE) {
        printf("오류: 잘못된 입력입니다.\n");
        return 1; // 입력 오류 시 비정상 종료
    }

    // 함수 호출: 배열명(주소)과 결과 변수의 주소(&) 전달
    calc_stats(data, start_index, end_index, &total_sum, &variance, &std_dev);

    // 결과 출력
    printf("\n--- 통계 결과 ---\n");
    printf("총합: %d\n", total_sum);
    printf("분산: %.4lf\n", variance);
    printf("표준편차: %.4lf\n", std_dev);

    return 0;
}