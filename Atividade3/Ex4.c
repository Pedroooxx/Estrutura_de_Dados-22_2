#include <stdio.h>
#include <stdlib.h>

int* subtracao(int *x, int *y){
    
    int cont;
    int *z = (int*)malloc(10 * sizeof(int));

    for(cont = 0; cont < 10; cont++){
        *(z+cont) = *(x+cont) - *(y+cont);
    }
    return z;
}
    void apresentar(int *z){
        int cont;
        for(cont = 0; cont < 10; cont++){
            printf("%d\t",*(z+cont));
    }
}

int main(){

    int *x, *y, *z;
    int cont;

    x = (int*)malloc(10 * sizeof(int));
    y = (int*)malloc(10 * sizeof(int));

    for(cont=0;cont<10;cont++){
        printf("Informe o %d valor de A: ", cont+1);
        scanf("%d",(x+cont));
    }

    for(cont=0;cont<10;cont++){
        printf("Informe o %d valor de B: ", cont+1);
        scanf("%d",(y+cont));
    }

    z = subtracao(x, y);

    apresentar(z);

    return 0;

}