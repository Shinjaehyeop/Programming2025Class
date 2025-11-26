#include <stdio.h> 

// 함수 정의: 두 정수(a, b)를 비교하여 큰 값을 반환하는 함수  

int get_max(int a, int b) {

	if (a > b) {

		return a; 	// a가 더 크면 a를 반환  

	}
	else {

		return b;	 // 그렇지 않으면 b를 반환  

	}

}

int main(void) {

	int val1 = 50;

	int val2 = 35;

	int max_val;

	// 함수 호출: get_max 함수를 호출하고 결과를 max_val에 저장 
	max_val = get_max(val1, val2);

	// 결과 출력 
	printf("두 수(%d, %d) 중 큰 값은 %d입니다.\n", val1, val2, max_val);

	return 0;

}