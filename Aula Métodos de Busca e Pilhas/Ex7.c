#include<stdio.h>
#include<stdlib.h>
#define N 30 //n�mero m�ximo de elementos

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

void pilha_push(Pilha *p, char v)
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

int pilha_pop(Pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return -1;
    }
    p->topo = p->topo - 1;
    return p->vet[p->topo];
}

void imprimir_pilha(Pilha *p){//Apenas para debug da pilha. N�o faz parte das opera��es.
 int i;

    printf("\n");

 for(i=0;i < p->topo;i++){
    printf("%c", p->vet[i]);
 }
}

int igualdade(Pilha *p, char aux[], int comp){

    for(int i = 0; i < comp; i++){

        if(aux[i] != p->vet[i]){

            return -1;
        }
    }
    return 0;
}

void testa_palindromo(Pilha *p, int comp){

    char aux[N], auxi;
    int esq, dir, res;
    int i;

    esq = 0;
    dir = comp-1;

    do{

        auxi = p->vet[dir];
        aux[dir] = p->vet[esq];
        aux[esq] = auxi;

        dir--;
        esq++;

        i++;

    }while(esq != dir && esq < dir);
        
    if(comp %2 != 0)
        aux[dir] = p->vet[esq];

    res = igualdade(p, aux, comp);

    if(res == -1)
        printf(" NAO EH um Palindromo.");

    if(res == 0)
        printf(" EH um Palindromo.");
}

int main(){

    int i = 0, comp;

    char palavra[N] = {"REVIVER"};
    Pilha *p;
    p = criar_pilha();

    while(palavra[i] != '\0'){

        pilha_push(p, palavra[i]);

        i++;
    }

    imprimir_pilha(p);

    comp = i;
    
    testa_palindromo(p, comp);
    
    return -1;
}