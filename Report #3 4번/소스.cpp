#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <math.h>   

int calculate_sum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculate_variance(const int arr[], int size, double mean) {
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow((arr[i] - mean), 2);
    }
    return variance / size;
}

double calculate_std_dev(double variance) {
    return sqrt(variance);
}

int main(void) {
    int numbers[10];
    int size = 10;
    int min_range = 1, max_range = 100;
    int sum;
    double mean, variance, std_dev;

    if (min_range >= max_range) {
        printf("오류: 범위 설정이 잘못되었습니다. (min >= max)\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        numbers[i] = (rand() % (max_range - min_range + 1)) + min_range;
    }

    sum = calculate_sum(numbers, size);

    mean = (double)sum / size;

    variance = calculate_variance(numbers, size, mean);

    std_dev = calculate_std_dev(variance);

    printf("--- 난수 통계 계산 결과 ---\n");
    printf("생성된 정수: ");
    for (int i = 0; i < size; i++) {
        printf("%d%s", numbers[i], (i == size - 1) ? "" : ", ");
    }
    printf("\n");
    printf("총합: %d\n", sum);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", std_dev);

    return 0;
}