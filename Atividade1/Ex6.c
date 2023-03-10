#include <stdio.h>
#include <stdlib.h>

int fatorial(int num){

    int cont, res;

    res = num;

        do{

            res = res * (num - 1);
            num--;

        }while(num > 1);

    return res;
}

int main(){

    int num[5], fat[5], cont;

    for(cont = 0; cont < 5; cont ++){

        printf("Digite o %d numero: ",cont+1);
        scanf("%d",&num[cont]);
    }

    for(cont = 0; cont < 5; cont++){

        fat[cont] = fatorial(num[cont]);
    }

    printf("%d %d %d %d %d\n",num[0],num[1],num[2],num[3],num[4]);
    printf("%d %d %d %d %d",fat[0],fat[1],fat[2],fat[3],fat[4]);

    return 0;
}