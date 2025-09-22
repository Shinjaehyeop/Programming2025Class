#include <stdio.h>

int main(void)
{
int age = 25;
unsigned int count = 3000000000;
float score = 93.5f;
const char* title = "Besic Constants";
const char* name = "jaehyeop";
char initial = name[0];
printf("=== %s ===\n Name \t : %s\n Initial : %c\n Age : %d\n Score \t : %.6f\n Count \t : %u\n", title, name, initial, age, score, count);
return 0;
}