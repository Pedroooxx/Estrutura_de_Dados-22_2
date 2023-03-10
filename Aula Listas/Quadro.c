#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20

typedef struct No {
    int info;
    struct No* prox;
} No;


typedef struct Lista {
    No* inicio;
} Lista;

Lista* criar_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int lista_vazia(Lista *l){
    return (l->inicio==NULL);
}

No* criar_no(int v){
    No *n = (No*)malloc(sizeof(No));
    n->info = v;
    n->prox = NULL;
    return n;
}

int info_no(No *n){
    return n->info;

}

int tamanho_lista(Lista *l){
    int tam = 0;
    No *aux = l->inicio;

    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }

    return tam;
}

void mostrar_lista(Lista *l){
    No* aux = l->inicio;
    if(lista_vazia(l))
        printf("Lista Vazia\n\n");
    else
        printf("Lista(%d): \n",tamanho_lista(l));
    while(aux!=NULL){
        printf("%d, ",info_no(aux));
        aux = aux->prox;
    }
    printf("\n");
}

No* adicionar_inicio(Lista *l, int v){
    No *novo = criar_no(v);
    novo->prox = l->inicio;
    l->inicio = novo;
    return novo;
}

int indice_no(Lista *l, int v){
    int pos = 0;
    No *aux = l->inicio;
    while(aux!=NULL){
        if(aux->info == v){
            return pos;
        }
        pos++;
        aux = aux->prox;
    }
    return -1;
}

void inserir_par_impar(Lista *l){

    int aux[N], pares[N], impares[N];
    int i = 0, i2;
    int i_par = 0, i_impar = 0;

    No* num = l->inicio;

    while(num!=NULL){

        aux[i] = info_no(num);
        num = num->prox;

        i++;
    }
    
    i2 = i;

    while(i>0){
    
        //del_primeiro_no(l);

        i--;
    }

    for(i = 0; (i_par+i_impar) < i2; i++){
        
        if(aux[i] % 2 == 0){

            pares[i_par] = aux[i];

            i_par++;
        }
        else{
            impares[i_impar] = aux[i];

            i_impar++;
        }
    }
    i = 0;

        while(i_par > 0){

            aux[i] = pares[i_par-1];

            i_par--;

            i++;

        }
        while(i_impar > 0){

            aux[i] = impares[i_impar-1];

            i_impar--;

            i++;
        }

        i2 = i;
    
    for(i = 0; i < i2; i++){
        printf("\t%d", aux[i]);
    }

    i = 0;

    /*

    while(aux[i] > i2){
    
        adicionar_inicio(l,aux[i]);

        i++;
    }

    mostrar_lista(l);

    */
}

int main(){

    Lista *l = criar_lista();

    adicionar_inicio(l,47);
    
    adicionar_inicio(l,34);

    adicionar_inicio(l,21);

    adicionar_inicio(l,11);

    adicionar_inicio(l,4);

    inserir_par_impar(l);
    
    return -1;
}