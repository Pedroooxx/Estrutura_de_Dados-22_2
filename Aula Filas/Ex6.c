#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int teste_impar(Fila *f){

    int i, cont_impar = 0;
    
    for(i = 0; i < N; i++){

        if(f->vet[f->ini] % 2 != 0){

            cont_impar++;
        }
        desenfileirar_fila(f);
    }
    return cont_impar;
}

void intercala_filas(Fila *f1, Fila *f2, Fila *f3){

    int i = 1;

        while(f1->ini != f1->fim){

        enfileirar_fila(f3, f1->vet[f1->ini]);

        enfileirar_fila(f3, f2->vet[f2->ini]);

        desenfileirar_fila(f1);

        desenfileirar_fila(f2);

        i++;
        }

    imprimir_fila(f3);
}

int main() {

    Fila *f1 = criar_fila();
    Fila *f2 = criar_fila();
    Fila *f3 = criar_fila();

    int vetA[N] = {10,63,14};
    int vetB[N] = {11,64,15};
    
    int i = 0, cont_impar;

    while(vetA[i] != 0){

        enfileirar_fila(f1, vetA[i]);

        i++;
    }
    i = 0;

    while(vetB[i] != 0){

        enfileirar_fila(f2, vetB[i]);

        i++;
    }

    intercala_filas(f1,f2,f3);

    return -1;
}