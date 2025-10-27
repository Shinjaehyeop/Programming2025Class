#include <stdio.h>

int rec_func(int n);

int main(void)
{
    int n = 10;
    int sum;

    sum = rec_func(n);

    printf("%d\n", sum);

    return 0;
}

int rec_func(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + rec_func(n - 1);
}