#include <stdio.h>

int main() {
    char ch = 'A';
    const char* msg = "Char/String & Escapes";
    int code = ch;
    const char* line1 = "First line";
    const char* quotes1 = "\"double quotes\"";
    const char* quotes2 = "'single quotes'";
    float avg = 87.345;

    printf("=== %s ===\n\n", msg);
    printf("Char : %c, code: %d\n", ch, code);
    printf("Message:\n");
    printf("%s\n", line1);
    printf("\tIndented second line\n");
    printf("Third line\n");
    printf("Quotes: %s and %s\n", quotes1, quotes2);
    printf("Backslash: \\\n");
    printf("Average: [ %8.2f ]\n", avg);

    return 0;
}