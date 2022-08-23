#include <stdio.h>
#define Ok 0
#define max 100

int main()
{
    int num = 0;
    while (num <= max)
    {
        if (num % 2 != 0)
        {
            printf("%d, ", num);
        }
        num++;
    }

    return Ok;
}