#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef struct
{
    int ini;
    int fim;
    char vet[N];
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

void enfileirar_fila(Fila *f,char c){
    if(fila_cheia(f)){
        printf("Fila Cheia\n");
        return;
    }
   f->vet[f->fim % N] = c;
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
        printf("%c",f->vet[i%N]);
    }
    printf("<--fim\n");
}

void incluir_pessoa(Fila *f, char nome[30]){

    int tam, i;

    tam = strlen(nome);

    for(i = 0; i <= tam; i++){

        enfileirar_fila(f, nome[i]);
    }
}

void realizar_atendimento(Fila *f){

    int cont = 0;

        printf("\nCliente: ");

        while(f->vet[f->ini] != '\0'){

            printf("%c",f->vet[f->ini]);

            desenfileirar_fila(f);
        }
        printf("\nAtendimento Mesa: %d", rand() % 20);
        desenfileirar_fila(f);
}

int main() {

    Fila *f = criar_fila();
    char nome1[30] = {"Keanu Reeves"};
    char nome2[30] = {"Jeffrey Dean Morgan"};
    int rep = 0, i;

    incluir_pessoa(f, nome1);
    incluir_pessoa(f, nome2);

    realizar_atendimento(f);
    realizar_atendimento(f);

    return -1;
}