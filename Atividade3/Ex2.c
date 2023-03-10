#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y){

    int z;

    z = *x;
    *x = *y;
    *y = z;

}

int main(){

    int x = 10, y = 20;

    printf("Antes: A: %d e B: %d", x, y);

    troca(&x, &y);

    printf("Depois: A: %d e B: %d", x, y);

    return 0;
}