#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// 무슨 일을 하는 함수인지 실행해보고 주석 작성
// 키보드 입력 버퍼에 남아있는 개행 문자등의 잔여 데이터를 제거하여 다음 입력 함수가 오작동하는 것을 방지한다.
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ;
    }
}

int main(void)
{
    char str1[100];
    char str2[100];
    char copy[100];
    char sentence[200];
    char temp[200];

    char* pos;
    char ch;

    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    printf("Enter first string (no spaces): ");
    scanf("%99s", p_str1);

    printf("Enter second string (no spaces): ");
    scanf("%99s", p_str2);

    printf("\n--- Printed strings (using puts) ---\n");
    puts(p_str1);
    puts(p_str2);

    // 무슨 일을 하는 부분인지 작성
    // strlen (문자열 길이) 실습
    printf("\n--- strlen practice ---\n");
    printf("Length of str1: %zu\n", strlen(p_str1));
    printf("Length of str2: %zu\n", strlen(p_str2));
    // --------------------------------------------------
    // 왜 여기에 이 함수를 넣었는지 작성
    //이전 scanf 호출 후 입력 버퍼에 남아있는 개행 문자(\n)를 제거하여, 다음 fgets 함수가 예상대로 사용자로부터 한 줄 전체를 입력받을 수 있도록 하기 위함이다.
    clear_input_buffer();
    printf("\nEnter one sentence (can include spaces): ");
    fgets(p_sentence, sizeof(sentence), stdin);
    printf("\nYou entered (sentence) = ");
    puts(p_sentence);

    // --------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #1: strcpy 실습 ---\n");
    strcpy(p_copy, p_str1);
    printf("copy = ");
    puts(p_copy);
    // --------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #2: strcat 실습 ---\n");
    if (strlen(p_str1) + strlen(p_str2) < sizeof(str1)) {
        strcat(p_str1, p_str2);
        printf("After concatenation, str1 = ");
        puts(p_str1);
    }
    else {
        printf("str1 buffer is too small; cannot perform strcat!\n");
    }
    // --------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #3: strcmp 실습 ---\n");
    {
        int cmp = strcmp(p_str1, p_str2);
        if (cmp == 0) {
            printf("str1 and str2 are equal.\n");
        }
        else if (cmp < 0) {
            printf("In lexicographical order, str1 comes before str2.\n");
        }
        else {
            printf("In lexicographical order, str1 comes after str2.\n");
        }
    }
    // --------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #4: strchr 실습 ---\n");
    printf("\nEnter a character to search for: ");
    scanf(" %c", &ch);
    pos = strchr(p_str1, ch);
    if (pos != NULL) {
        printf("'%c' is at index %ld (0-based) in str1.\n",
            ch, (long)(pos - p_str1));
    }
    else {
        printf("'%c' is not found in str1.\n", ch);
    }
    // --------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #5: strchr 실습 ---\n");
    pos = strstr(p_sentence, p_str2);
    if (pos != NULL) {
        printf("\nFound \"%s\" inside sentence.\n",
            p_str2);
        printf("Substring starting from the found position: ");
        puts(pos);
    }
    else {
        printf("Could not find \"%s\" in sentence.\n",
            p_str2);
    }
    // --------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #6: strtok 실습 ---\n");
    printf("\n--- strtok practice: split sentence by spaces ---\n");
    // 왜 이 실습에서는 temp에 문자열을 복사하는가?
    //strtok 함수가 원본 문자열을 훼손하는 특성 때문에 복사본이 필요하다.
    strcpy(p_temp, p_sentence);
    char* token = strtok(p_temp, " ");
    int i = 1;
    while (token != NULL) {
        printf("Token %d: ", i++);
        puts(token);
        token = strtok(NULL, " ");
    }
    // --------------------------------------------------

    printf("\nProgram finished.\n");
    return 0;
}