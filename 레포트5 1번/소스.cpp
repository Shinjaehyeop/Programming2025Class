#include <stdio.h>
#include <stdlib.h> // rand, srand, exit 사용
#include <time.h>   // time 함수 사용

#define SIZE 3      // 행렬 크기 (3x3)
#define RAND_RANGE 10 // 난수 범위: 0부터 (RAND_RANGE-1)까지

// 함수 원형 선언 (2차원 배열 포인터 사용)
// 2차원 배열을 함수에 전달할 때는 열의 크기(SIZE)를 명시해야 함
void GenerateMatrix(int arr[][SIZE]);
void PrintMatrix(int arr[][SIZE], const char* msg);
void AddMatrix(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
void SubtractMatrix(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
void ScalarMultiplyMatrix(int A[][SIZE], int scalar, int R[][SIZE]);
void MultiplyMatrix(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
int CalculateDeterminant(int A[][SIZE]);


// ===============================================
// 메인 함수
// ===============================================
int main(void) {
    int matrixA[SIZE][SIZE];
    int matrixB[SIZE][SIZE];
    int scalarC;

    // 결과 행렬들을 선언 (Call by Reference로 결과 저장)
    int R_add[SIZE][SIZE];
    int R_sub[SIZE][SIZE];
    int R_scalar[SIZE][SIZE];
    int R_mul[SIZE][SIZE];

    int determinantA; // 행렬식 값 저장 변수

    srand(time(NULL));

    // 1. 행렬 및 스칼라 생성
    GenerateMatrix(matrixA); // 행렬 A 생성 (주소 전달)
    GenerateMatrix(matrixB); // 행렬 B 생성 (주소 전달)
    scalarC = rand() % RAND_RANGE + 1; // 스칼라 C 생성 (1부터 RAND_RANGE)

    // 초기 행렬 출력
    PrintMatrix(matrixA, "행렬 A");
    PrintMatrix(matrixB, "행렬 B");
    printf("스칼라 C: %d\n", scalarC);
    printf("-----------------------------------------\n");

    // 2. 행렬식 계산 및 역행렬 가능성 확인
    determinantA = CalculateDeterminant(matrixA);
    printf("행렬 A의 행렬식 (Determinant): %d\n", determinantA);

    if (determinantA != 0) {
        printf("-> 역행렬 계산 가능 상태입니다.\n");
    }
    else {
        printf("-> 역행렬 계산 불가 상태입니다 (행렬식=0).\n");
    }
    printf("-----------------------------------------\n");

    // 3. 연산 수행 (함수 호출)
    AddMatrix(matrixA, matrixB, R_add);
    SubtractMatrix(matrixA, matrixB, R_sub);
    ScalarMultiplyMatrix(matrixA, scalarC, R_scalar);
    MultiplyMatrix(matrixA, matrixB, R_mul);

    // 4. 결과 출력
    PrintMatrix(R_add, "덧셈 (A + B)");
    PrintMatrix(R_sub, "뺄셈 (A - B)");
    PrintMatrix(R_scalar, "스칼라 곱 (A * C)");
    PrintMatrix(R_mul, "행렬 곱 (A x B)");

    return 0;
}

// ===============================================
// 함수 정의 (2차원 배열 포인터 사용)
// ===============================================

// 난수 행렬 생성 함수 (결과를 Call by Reference로 R에 저장)
void GenerateMatrix(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 난수 생성 및 배열 요소에 저장
            arr[i][j] = rand() % RAND_RANGE;
        }
    }
}

// 행렬 출력 함수
void PrintMatrix(int arr[][SIZE], const char* msg) {
    printf("--- %s ---\n", msg);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

// 행렬 덧셈 함수
void AddMatrix(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 행렬 뺄셈 함수
void SubtractMatrix(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}

// 스칼라 곱셈 함수
void ScalarMultiplyMatrix(int A[][SIZE], int scalar, int R[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = A[i][j] * scalar;
        }
    }
}

// 행렬 곱셈 함수
void MultiplyMatrix(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = 0; // 결과 요소 초기화
            for (int k = 0; k < SIZE; k++) {
                // 행렬 곱셈 수식: C[i][j] = sum(A[i][k] * B[k][j])
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 3x3 행렬식 (Determinant) 계산 함수
int CalculateDeterminant(int A[][SIZE]) {
    int det;

    // 행렬식 공식 적용 (3x3 행렬식 공식)
    det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
        A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
        A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    return det;
}