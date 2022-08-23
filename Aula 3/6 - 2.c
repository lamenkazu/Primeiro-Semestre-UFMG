#include <stdio.h>
#define Ok 0
#define max 100

int main()
{
    for (int cont = 0; cont < max; cont++){

        if (cont % 2 != 0){
            printf("%d, ", cont);
        }
        
    }

    return Ok;
}