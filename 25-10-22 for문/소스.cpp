#include <stdio.h>
#include <stdlib.h>

int main() {
    char input_str[10];
    int dan;

    printf("Enter a number (2-9) for a single table, or '0' for all tables: ");

    if (fgets(input_str, sizeof(input_str), stdin) == NULL) {
        return 1;
    }

    dan = atoi(input_str);

    if (dan >= 2 && dan <= 9) {
        printf("\n*** %d Times Table ***\n", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d * %d = %d\n", dan, i, dan * i);
        }
    }
    else if (dan == 0) {
        printf("\n*** All Multiplication Tables (2-9) ***\n");
        for (int i = 2; i <= 9; i++) {
            printf("\n--- %d Dan ---\n", i);
            for (int j = 1; j <= 9; j++) {
                printf("%d * %d = %d\n", i, j, i * j);
            }
        }
    }
    else {
        printf("Input must be 0 or a number between 2 and 9.\n");
    }

    return 0;
}