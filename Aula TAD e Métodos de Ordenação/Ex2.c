#include <stdio.h>
#include <stdlib.h>

    typedef struct {

        int numero, saldo;

    }conta;

    conta *criarConta(int num, int val){
        conta *c = (conta*)malloc(sizeof(conta));
        c ->numero = num;
        c ->saldo = val;
        return c;
    }

    conta* lerConta(){

        int num, val;

        printf("\nDigite o numero da conta: ");
        scanf("%d",&num);

        printf("\nDigite o valor do saldo: ");
        scanf("%d",&val);

        return criarConta(num, val);
    }

    conta* depositoConta(conta *c){

        int num, val;
        
        int deposito;

        printf("\nDigite o valor do deposito: ");
        scanf("%d",&deposito);

        c->saldo += deposito;

        printf("\n-- Dados Atualizados--\n");

        return criarConta(num, val);
    }

    conta* saqueConta(conta *c){

        int num, val;

        int saque;

        printf("\nDigite o valor do saque: ");
        scanf("%d",&saque);

        c->saldo -= saque;

        printf("\n-- Dados Atualizados--\n");

        return criarConta(num, val);
    }      

    void apresentarConta(conta *c){

        printf("\nConta: %d", c->numero);
        printf("\n\nSaldo: %d", c->saldo);
    }

int main(){

    conta *c;
    int op;

    c = lerConta();

    printf("\n-- Operações Bancarias-- \n");
    printf("\n1) Deposito \n");
    printf("\n2) Saque \n");
    printf("\n0) Sair. \n");
    printf("\n---> ");
    scanf("%d",&op);

        if(op == 1){
            c = depositoConta(c);
        }
        if(op == 2){
            c = saqueConta(c);
        }

    apresentarConta(c);

    return 0;
}