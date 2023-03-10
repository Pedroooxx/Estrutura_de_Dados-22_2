#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 7

typedef struct
{
    int topo;
    char vet[N];
} Pilha;

Pilha* criar_pilha()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

int pilha_vazia(Pilha *p)
{
    return (p->topo==0);
}

int pilha_cheia(Pilha *p)
{
    return (p->topo==N);
}

void liberar_pilha(Pilha *p)
{
    free(p);
}

void pilha_push(Pilha *p, char v, int i)
{
    if(pilha_cheia(p))
    {
        printf("A capacidade da pilha estourou.\n");
        return;
    }
    p->vet[p->topo] = v;
    p->topo++;
}

int mostrar_topo(Pilha *p)
{
    if(pilha_vazia(p))
    {
        printf("A pilha esta vazia.\n");
        return -1;
    }
    return p->vet[p->topo-1];
}

char pilha_pop(Pilha *p)
{
    if(pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    p->topo = p->topo - 1;
    return p->vet[p->topo];
}

void imprimir_pilha(Pilha *p)
{
    int i;
    printf("PILHA\n");
    for(i=0; i < p->topo; i++)
    {
        printf("[%c]  ", p->vet[i]);
    }
}

int calc(int num1, int num2, char opr){

    int res;

    if(opr == '+'){
        res = num1 + num2;
        return res;
    }
    if(opr == '-'){
        res = num1 - num2;
        return res;
    }
    if(opr == '*'){
        res = num1 * num2;
        return res;
    }
    if(opr == '/'){
        res = num1 / num2;
        return res;
    }
}

int converte_char(char num){

    if(num == '0')
        return 0;
    if(num == '1')
        return 1;
    if(num == '2')
        return 2;
    if(num == '3')
        return 3;
    if(num == '4')
        return 4;
    if(num == '5')
        return 5;
    if(num == '6')
        return 6;
    if(num == '7')
        return 7;
    if(num == '8')
        return 8;
    if(num == '9')
        return 9;

}

void calc_pfixa(Pilha *p, char vet[N]){
    
    int  i, res;
    char *convert;

    for(i = 0; i < N; i++){

        pilha_push(p, vet[i], i);

        if(vet[i] == '+' || vet[i] == '-' || vet[i] == '*' || vet[i] == '/'){
            
            int aux1 = converte_char(p->vet[(p->topo)-3]);
            int aux2 = converte_char(p->vet[(p->topo)-2]);

            res = calc(aux1, aux2, vet[i]);

            pilha_pop(p);
            pilha_pop(p);
            pilha_pop(p);

            pilha_push(p, res, i);

            printf("\n\t%d\n",res);

        }
    }
    printf("\n\tResposta Final: [%d]\n",res);
}

int main(){

    char vet[N] = {"25+49+*"};
    Pilha *p;
    p = criar_pilha();

    calc_pfixa(p, vet);

    return 0;
}