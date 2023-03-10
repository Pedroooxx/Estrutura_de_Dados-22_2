#include <stdio.h>
#include <stdlib.h>

int primo(int num){
    
    int metade, resp;

    for(metade = (num / 2) + 1; metade > 1; metade--){

        if(num % metade != 0){
            resp = 1;
        }
        else
            resp = 0;
    }

    return resp;
}

int main(){

    int num, resp;

    printf("Digite um numero: ");
    scanf("%d",&num);

    resp = primo(num);

    printf("%d",resp);

    return 0;
}