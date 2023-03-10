#include<stdio.h>
#include<stdlib.h>
#define N 3 //n�mero m�ximo de elementos

typedef struct
{
    int topo;
    int vet[N];
} Pilha;

/*Opera��es b�sicas com pilhas*/
Pilha* criar_pilha();
void pilha_push (Pilha*, int);
int pilha_vazia(Pilha*);
int pilha_cheia(Pilha*);
void liberar_pilha(Pilha*);
void pilha_push(Pilha*, int);
int pilha_pop(Pilha*);
int mostrar_topo(Pilha*);
void imprimir_pilha(Pilha*);

int main()
{
    Pilha *p;
    p = criar_pilha();
    pilha_push(p,15);
    printf("Pilha topo: %d\n",mostrar_topo(p));
    pilha_push(p,20);
    printf("Pilha topo: %d\n",mostrar_topo(p));
    pilha_push(p,25);
    printf("Pilha topo: %d\n",mostrar_topo(p));
    imprimir_pilha(p);
    printf("Retirando %d ....\n",pilha_pop(p));
    imprimir_pilha(p);
    printf("Retirando %d ....\n",pilha_pop(p));
    imprimir_pilha(p);
    printf("Retirando %d ....\n",pilha_pop(p));
    imprimir_pilha(p);
    printf("Retirando %d ....\n",pilha_pop(p));
    liberar_pilha(p);
    return -1;
}

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

void pilha_push(Pilha *p, int v)
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

 for(i=0;i < p->topo;i++){
    printf("[%d]  ", p->vet[i]);
 }
 printf("<--topo\n");

}