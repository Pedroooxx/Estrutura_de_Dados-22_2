#include <stdio.h>
#include <stdlib.h>

int potencia(int num, int res, int pot){
    
    if(pot == 0)
        return 0;
    if(pot == 1)
        return num;
    else{
        res = res * potencia(num, res, pot-1);
    }
}

int main(){

    int num, pot, res;

    printf("Digite a base da potencia: ");
    scanf("%d",&num);
    printf("Digite o expoente da potencia: ");
    scanf("%d",&pot);

    res = num;

    res = potencia(num, res, pot);

    printf("Resultado: %d",res);

    return 0;
}