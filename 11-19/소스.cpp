#include <stdio.h>

void swap(int* pa, int* pb)
{
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(void)
{
    int a = 20;
    int* pa;

    pa = &a;

    printf("1. [포인터 기본] 변수 a의 초기값 (변수명으로): %d\n", a);
    *pa = 10;
    printf("1. [포인터 기본] a의 주소(&a): %u, pa에 저장된 주소(pa): %u\n", &a, pa);
    printf("1. [포인터 기본] a의 바뀐 값 (포인터로): %d\n", *pa);
    printf("----------------------------------------\n");

    int x = 10, y = 20;

    printf("2. [값 교환] 교환 전: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("2. [값 교환] 교환 후: x = %d, y = %d\n", x, y);
    printf("----------------------------------------\n");

    return 0;
}