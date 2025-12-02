#include <stdio.h>
#include <stdlib.h> // rand, srand, exit 함수 사용
#include <time.h>   // time 함수 사용

// 문제 요구사항에 따른 상수 정의
#define ARRAY_SIZE 10
#define MIN_VAL -100.0
#define MAX_VAL 100.0

// 정렬 방식을 지정하는 상수
#define ASCENDING  1  // 오름차순
#define DESCENDING 0  // 내림차순

// 함수 원형 선언 (배열명을 포인터로 받음)
void CalcSortArray(double* arr, int size, int sort_type);
void PrintArray(double* arr, int size, const char* msg);

// ===============================================
// 메인 함수
// ===============================================
int main(void) {
    // 배열 선언: 크기 10의 double형 배열 선언
    double input_array[ARRAY_SIZE];
    int i; // C90 호환을 위한 변수 선언

    // 난수 시드 초기화
    srand(time(NULL));

    // 1. 입력 (난수 생성): -100.0 ~ +100.0 범위의 실수 생성
    for (i = 0; i < ARRAY_SIZE; i++) {
        // 포인터 연산을 이용하여 배열 요소에 접근 (배열/포인터 상호 호환 문법)
        // input_array + i 는 i번째 요소의 주소, *을 붙여 값에 접근 [cite: 4989]
        *(input_array + i) = (rand() / (double)RAND_MAX) * (MAX_VAL - MIN_VAL) + MIN_VAL;
    }

    // 2. 초기 배열 출력
    // 배열명(input_array)을 포인터처럼 함수에 전달 [cite: 5099]
    PrintArray(input_array, ARRAY_SIZE, "초기 생성된 배열");

    // 3. 오름차순 정렬 및 출력 (인자로 ASCENDING 전달)
    CalcSortArray(input_array, ARRAY_SIZE, ASCENDING);
    PrintArray(input_array, ARRAY_SIZE, "오름차순 (ASCENDING) 정렬 결과");

    // 4. 내림차순 정렬 및 출력 (인자로 DESCENDING 전달)
    CalcSortArray(input_array, ARRAY_SIZE, DESCENDING);
    PrintArray(input_array, ARRAY_SIZE, "내림차순 (DESCENDING) 정렬 결과");

    return 0;
}

// ===============================================
// 함수 정의
// ===============================================

// 배열 정렬 함수 (선택 정렬 - Selection Sort 활용)
void CalcSortArray(double* arr, int size, int sort_type) {
    double temp;
    int i, j; // C90 호환을 위한 변수 선언

    // 배열 주소(arr)를 포인터로 받아 중첩 for 문을 이용해 정렬 수행
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {

            int should_swap = 0;

            // 정렬 방식 선택 (인자 sort_type에 따라 정렬 기준 변경)
            if (sort_type == ASCENDING) {
                // 오름차순: 현재 요소가 다음 요소보다 크면 교환
                should_swap = (*(arr + i) > *(arr + j)); // 포인터 연산으로 값 비교
            }
            else { // DESCENDING
                // 내림차순: 현재 요소가 다음 요소보다 작으면 교환
                should_swap = (*(arr + i) < *(arr + j)); // 포인터 연산으로 값 비교
            }

            // 교환 (Swap) 로직: 포인터 연산을 통해 원본 배열의 값 변경
            if (should_swap) {
                temp = *(arr + i);      // 현재 요소 값 임시 저장
                *(arr + i) = *(arr + j);  // 다음 요소 값을 현재 위치에 저장
                *(arr + j) = temp;      // 임시 값을 다음 위치에 저장
            }
        }
    }
    // 주석 충실히 작성: arr 배열 포인터를 통해 원본 데이터를 정렬하여 Call by Reference로 결과를 반환함.
}


// 배열 출력 함수 (배열 주소를 받아 내용을 순차적으로 출력)
void PrintArray(double* arr, int size, const char* msg) {
    int i; // C90 호환을 위한 변수 선언
    printf("--- %s ---\n", msg);

    // 배열/포인터 상호 호환 문법 활용 (배열식 arr[i] 사용)
    for (i = 0; i < size; i++) {
        printf("[%.2lf] ", arr[i]); // arr[i] == *(arr + i) [cite: 4989]
    }
    printf("\n\n");
    // 주석 충실히 작성: arr 배열 포인터를 받아 배열식으로 순회하며 출력함.
}