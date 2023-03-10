#include <stdio.h>
#include <stdlib.h>
#define N 5

// - CODIGOS FILAS - ========================================================================================================

typedef struct
{
    int ini;
    int fim;
    int vet[N];
} Fila;

Fila* criar_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = 0;
    f->fim = 0;
    return f;
}

void enfileirar_fila(Fila *f,int v){

   f->vet[f->fim % N] = v;
   f->fim++;
   //f->vet[f->fim++ % N] = v;
}

int desenfileirar_fila(Fila *f){
    int aux;

    aux = f->vet[f->ini % N];
    f->ini++;
    return aux;
}

void imprimir_fila(Fila *f){
    int i;
    printf("Dados na Fila:\n");
    //printf("f->ini:%d \n f->fim:%d\n",f->ini,f->fim);
    printf("Ini-->\t");
    for(i=f->ini;i<f->fim;i++){
        printf("[%d]\t",f->vet[i%N]);
    }
    printf("<--fim\n");
}

//===========================================================================================================================

// - CODIGOS PILHAS - =======================================================================================================

typedef struct
{
    int topo;
    int vet[N];
} Pilha;

Pilha* criar_pilha()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void pilha_push(Pilha *p, int v)
{
    p->vet[p->topo] = v;
    p->topo++;
}

int pilha_pop(Pilha *p){
    
    p->topo = p->topo - 1;
    return p->vet[p->topo];
}

void imprimir_pilha(Pilha *p){//Apenas para debug da pilha. N�o faz parte das opera��es.
 int i;

 for(i=0;i < p->topo-1;i++){
    printf("[%d]  ", p->vet[i]);
 }

}

//===========================================================================================================================

void adicionar_elementos(Fila *f, Pilha *p){

    int i, num;

    for(i = 0; i < N; i++){

        printf("Digite o %d° numero: ", i+1);
        scanf("%d", &num);

        enfileirar_fila(f, num);
    }
}

void inverter_fila(Fila *f, Pilha *p){

    int i1, i2 = 0;

    for(i1 = N; i1 >= 0; i1--){

        pilha_push(p, f->vet[i1]);
        desenfileirar_fila(f);
    }
    for(i1 = N; i1 >= 0; i1--){

        enfileirar_fila(f, p->vet[i2]);
        i2++;
    }
}

int main() {

    Fila *f = criar_fila();
    Pilha *p = criar_pilha();

    adicionar_elementos(f, p);

    printf("\nFila antes: ");
    imprimir_fila(f);

    inverter_fila(f, p);

    printf("\nFila depois: ");
    imprimir_fila(f);

    return -1;
}