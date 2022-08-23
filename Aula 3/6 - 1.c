#include <stdio.h>
#define Ok 0
#define max 100

int main()
{
    int num = 0;

    do
    {
        if (num % 2 != 0)
        {
            printf("%d, ", num);
        }
        num++;
    } while (num <= max);

    return Ok;
}