#include <stdio.h> 

int main(void) {

    for (int dan = 2; dan <= 9; dan++) {

        printf("--- %d´Ü ---\n", dan);

        for (int num = 1; num <= 9; num++) {

            printf("%d x %d = %2d\n", dan, num, dan * num);

        }

    }

    return 0;

}