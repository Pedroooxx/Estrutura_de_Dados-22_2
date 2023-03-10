#include <stdio.h>
#include <stdlib.h>

char notaFinal(float n1, float n2, float n3, float n4){

    float media;

    media = ((n1 * 2) + (n2 * 3) + (n3 * 4) + (n4 * 5)) / 14;

    if(media >= 8.5)
    return 'A';
    if(media >= 7.0 && media < 8.5)
    return 'B';
    if(media >= 6.0 && media < 7.0)
    return 'C';
    if(media < 6.0)
    return 'D';
}

int main(){

    int cont;
    float nota[4];
    char conceito;

    for(cont = 0; cont < 4; cont++){
        printf("Digite a %dº nota: ",cont+1);
        scanf("%f",&nota[cont]);
    }

    conceito = notaFinal(nota[0],nota[1],nota[2],nota[3]);

    printf("O aluno recebeu nota: %c",conceito);

    return 0;
}