#include <stdio.h>
#include <stdlib.h>

void soma(int *x, int *y){

    int z;

    z = *x + *y;
    *x = z;

}

int main(){

    int x = 10, y = 20;

    soma(&x, &y);

    printf("Depois: A: %d", x);

    return 0;
}