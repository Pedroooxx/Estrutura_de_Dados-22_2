#include <stdio.h>
#include <stdlib.h>

    typedef struct cadastro{
        char nome[20];
        char email[35];
        int idade;
    }cadastro;

    void apresentar(cadastro pessoa){

        printf("\nNome: %s", pessoa.nome);
        printf("\nIdade: R$%d", pessoa.idade);
        printf("\nEmail: %s\n", pessoa.email);
    }

int main(){

    cadastro pessoa;

        fflush(stdin);

        printf("\nDigite o nome: ");
        gets( pessoa.nome);

        printf("\nDigite a idade: ");
        scanf("%d",&pessoa.idade);

        fflush(stdin);

        printf("\nDigite o email: ");
        gets(pessoa.email);

        apresentar(pessoa);    

    return 0;
}