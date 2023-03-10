#include <stdio.h>
#include <stdlib.h>
#define N 10

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

int fila_cheia(Fila *f){
    return (f->fim - f->ini == N);
}

int fila_vazia(Fila *f){
    return (f->ini == f->fim);
}

void enfileirar_fila(Fila *f,int v){
    if(fila_cheia(f)){
        printf("Fila Cheia\n");
        return;
    }
   f->vet[f->fim % N] = v;
   f->fim++;
   //f->vet[f->fim++ % N] = v;
}

int desenfileirar_fila(Fila *f){
    int aux;
    if(fila_vazia(f)){
        printf("Fila vazia\n");
        return -1;
    }
    aux = f->vet[f->ini % N];
    f->ini++;
    return aux;
}

void liberar_fila(Fila *f){
    free(f);
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

int teste_par(Fila *f){

    int i, cont_par = 0;
    
    for(i = 0; i < N; i++){

        if(f->vet[f->ini] % 2 == 0){

            cont_par++;
        }
        desenfileirar_fila(f);
    }
    return cont_par;
}

int main() {

    Fila *f = criar_fila();
    int vet[N] = {10,63,14,53,10,8,35,12,5,28};
    int i, cont_par;

    for(i = 0; i < N; i++){

        enfileirar_fila(f, vet[i]);
    }

    imprimir_fila(f);

    cont_par = teste_par(f);

    printf("%d numeros Pares.",cont_par);

    return -1;
}