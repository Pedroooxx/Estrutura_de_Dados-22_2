#include <stdio.h>
#include <stdlib.h>

    typedef struct cadastro{
        
        int matricula[20];
        char nome[20];
        float nota1;
        float nota2;
        float nota3;

    }cadastro;

    float calcular(float n1, float n2, float n3){

        float media;

        media = (n1 + n2 + n3) / 3;

        return media;
    }

    void apresentar(cadastro pessoa, float media){

        int cont;

        printf("\nNome: %s\n", pessoa.nome);
        printf("\nMedia: %.2f\n", media);
        
        if(media < 6){
            printf("\nStatus: REPROVADO\n"); 
        }
        else{
            printf("\nStatus: APROVADO\n"); 
        }
    }

int main(){

    int cont = 0;
    float media;

    cadastro pessoa[5];

        do{

        fflush(stdin);

        printf("\n\n**CADASTRO DO %d ALUNO**\n",(cont+1));

        printf("\nDigite o nome: ");
        gets( pessoa[cont].nome);

        fflush(stdin);

        printf("\nDigite a matricula: ");
        scanf("%d",&pessoa[cont].matricula);

        printf("\nDigite a primeira nota: ");
        scanf("%f",&pessoa[cont].nota1);

        printf("\nDigite a segunda nota: ");
        scanf("%f",&pessoa[cont].nota2);

        printf("\nDigite a terceira nota: ");
        scanf("%f",&pessoa[cont].nota3);

        media = calcular(pessoa[cont].nota1, pessoa[cont].nota2, pessoa[cont].nota3);

        apresentar(pessoa[cont], media);

        cont++;

        }while(cont < 5);
    
    return 0;
}