#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int generate_target(void) {
    srand(time(NULL));
    return (rand() % 100) + 1;
}

void up_down_game(void) {
    int target = generate_target();
    int guess;
    int max_tries = 10;
    int i;

    printf("--- UP & DOWN 게임 시작 ---\n");
    printf("1부터 100 사이의 숫자를 10번의 기회 안에 맞추세요.\n");

    for (i = 1; i <= max_tries; i++) {
        printf("시도 #%d > 숫자를 입력하세요: ", i);
        scanf("%d", &guess);

        if (guess == target) {
            printf("\n*** 정답입니다! %d번 만에 성공하셨습니다! ***\n", i);
            break;
        }
        else if (guess < target) {
            printf("UP! 더 큰 수를 입력하세요.\n");
        }
        else {
            printf("DOWN! 더 작은 수를 입력하세요.\n");
        }
    }

    if (i > max_tries) {
        printf("\n--- 기회 %d번을 모두 소진했습니다. 게임 실패 ---\n", max_tries);
        printf("정답은 %d였습니다.\n", target);
    }
}

int main(void) {
    up_down_game();
    return 0;
}