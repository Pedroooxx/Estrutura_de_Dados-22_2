#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct{

    char nome[30];
    char autor[25];

    int codigo;
    int ano;

} Livro;

int main(){

    Livro l[N];
    int i;

    for (i = 0; i < N; i++){

        printf("\nDigite o nome do Livro: ");
        fflush(stdin);
        scanf(" %s",l[i].nome);

        printf("Digite o nome do Autor: ");
        fflush(stdin);
        scanf(" %s",l[i].autor);

        printf("Digite o seu ano de publicacao: ");
        scanf(" %d ",&l[i].ano);

        l[i].codigo = rand() % 100;

    }

    for (int i = 0; i < N; i++){

        printf("LIVRO %d", i+1);

        printf("\nAutor = %s ", l[i].autor);
        printf("\nAno de Publicação = %d ", l[i].ano);
        printf("\nCodigo = %d \n\n", l[i].codigo);
    }

    int op1, op2;

    printf("\nGostaria de Saber mais");
    printf("\nsobre algum dos livros? ");
    printf("\nDigite: 1 = SIM | 2 = NAO -> ");
    fflush(stdin);
    scanf("%d", &op1);

    if(op1 == 1){

        printf("\nComo gostaria de saber mais?");
        printf("\nPelo codigo? Digite: 1");
        printf("\nPelo Autor e do ano de publicacao? Digite: 2");
        printf("\n-------> ");
        scanf("%d", &op2);
    }
    else{
        printf("\n\ntchau");
    }

    int cod, resp = -1;

    if(op2 == 1){

        printf("\nDigite o codigo do livro: ");
        scanf("%d",&cod);

        for (int i=0; i<N; i++){
            if(l[i].codigo == cod){
                resp = i;
            }
        }
    }

    char aut;
    int anoo;

    if(op2 == 2){

        int resp1 = 0, resp2 = 0;

        printf("\nDigite a primeira letra do nome do Autor do livro: ");
        fflush(stdin);
        scanf(" %c",&aut);

        printf("\nDigite o ano de lancamento do livro: ");
        scanf("%d",&anoo);

        for (int i=0; i<N; i++){
            if(l[i].autor[0] == aut){
                resp1 = i;
            }
        }
        for (int i=0; i<N; i++){
            if(l[i].ano == anoo){
                resp2 = i;
            }
        }
        if(resp1 == resp2){
            resp = resp1;
        }
        else{
            printf("Livro nao encontrado.");
            printf("-- TENTE NOVAMENTE --");
        }
    }

    printf("%d",resp);

    if((op2 == 1 || op2 == 2) && resp >= 0){
        printf("\n\n-- LIVRO BUSCADO --\n");
        printf("\nNome do Livro = %s ", l[resp].nome);
        printf("\nAutor = %s ", l[resp].autor);
        printf("\nAno de Publicação = %d ", l[resp].ano);
        printf("\nCodigo = %d \n\n", l[resp].codigo);
    }

    return 0;
}