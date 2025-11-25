#define _CRT_SECURE_NO_WARNINGS // scanf 사용 경고 (C4996)를 무시하기 위해 추가
#include <stdio.h>
#include <stdlib.h> // rand, srand, exit 함수 사용
#include <time.h>   // time 함수 사용

#define LOTTO_SIZE 6 // 로또 번호 개수
#define MAX_NUM 45   // 최대 숫자

// 중복 여부를 확인하는 헬퍼 함수
int is_duplicate(int* arr, int count, int num) {
    int i; // <--- C90 호환: 변수 선언 위치 수정
    for (i = 0; i < count; i++) { // 'int' 키워드 제거
        if (arr[i] == num) { // 배열식으로 포인터 접근
            return 1; // 중복됨
        }
    }
    return 0;
}

// 컴퓨터 로또 번호를 생성하는 함수 (Call by Reference)
void generate_lotto(int* lotto_ptr) {
    int i; // <--- C90 호환: 변수 선언 위치 수정
    int rand_num;

    srand(time(NULL)); // 난수 시드 초기화

    for (i = 0; i < LOTTO_SIZE; i++) { // 'int' 키워드 제거
        do {
            rand_num = (rand() % MAX_NUM) + 1; // 1~45 난수 생성
        } while (is_duplicate(lotto_ptr, i, rand_num)); // 중복 확인

        *(lotto_ptr + i) = rand_num; // 포인터 연산으로 값 저장
    }
}

// 사용자 로또 번호를 입력받는 함수 (Call by Reference)
void get_user_numbers(int* user_ptr) {
    int i; // <--- C90 호환: 변수 선언 위치 수정

    printf("로또 번호 6개를 1부터 %d 사이에서 입력하세요: ", MAX_NUM);

    for (i = 0; i < LOTTO_SIZE; i++) { // 'int' 키워드 제거
        // scanf에 배열 요소의 주소를 전달 (&user_ptr[i])
        if (scanf("%d", &user_ptr[i]) != 1 || user_ptr[i] < 1 || user_ptr[i] > MAX_NUM) {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            exit(1);
        }
    }
}

// 두 로또 번호를 비교하여 일치 개수를 반환하는 함수
int compare_lotto(int* comp_ptr, int* user_ptr) {
    int i, j; // <--- C90 호환: 변수 선언 위치 수정
    int match_count = 0;

    // 중첩 반복문으로 두 배열의 모든 요소 비교
    for (i = 0; i < LOTTO_SIZE; i++) { // 'int' 키워드 제거
        for (j = 0; j < LOTTO_SIZE; j++) { // 'int' 키워드 제거
            if (comp_ptr[i] == user_ptr[j]) {
                match_count++;
                break;
            }
        }
    }
    return match_count; // 일치 개수 반환
}

int main(void) {
    int comp_lotto[LOTTO_SIZE];
    int user_lotto[LOTTO_SIZE];
    int i; // <--- C90 호환: 변수 선언 위치 수정

    generate_lotto(comp_lotto);
    get_user_numbers(user_lotto);

    int matches = compare_lotto(comp_lotto, user_lotto);

    // 결과 출력
    printf("\n================ 로또 당첨 결과 ================\n");
    printf("1. 컴퓨터 로또 번호: ");
    for (i = 0; i < LOTTO_SIZE; i++) { // 'int' 키워드 제거
        printf("%2d ", comp_lotto[i]);
    }
    printf("\n2. 사용자 입력 번호: ");
    for (i = 0; i < LOTTO_SIZE; i++) { // 'int' 키워드 제거
        printf("%2d ", user_lotto[i]);
    }

    printf("\n\n* 일치하는 번호 개수: %d개\n", matches);

    // 당첨 여부 출력
    if (matches >= 3) {
        printf("-> 축하합니다! 당첨되었습니다.\n");
    }
    else {
        printf("-> 아쉽지만 다음 기회에.\n");
    }

    return 0;
}