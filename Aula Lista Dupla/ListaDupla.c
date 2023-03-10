
#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef struct No {
    int info;
    struct No* prox;
    struct No* ant;
} No;

typedef struct ListaDupla {
    No* inicio;
    No* fim;
} ListaDupla;

ListaDupla* criar_lista(){ //fun��o para cria��o da lista
    ListaDupla *l = (ListaDupla*)malloc(sizeof(ListaDupla));
    l->fim = NULL;
    l->inicio = NULL;
    return l;
}

int lista_vazia(ListaDupla *l){
    return (l->inicio==NULL);
}

No* criar_no(int v){
    No* n = (No*)malloc(sizeof(No));
    n->info = v;
    n->ant = NULL;
    n->prox = NULL;
    return n;
}

int info_no(No *n){
    return n->info;

}

int tamanho_lista(ListaDupla *l){
    int tam = 0;
    No *aux = l->fim;

    while(aux!=NULL){
        tam++;
        aux = aux->ant;
    }

    return tam;
}

void mostrar_lista(ListaDupla *l){
    No* aux = l->inicio;
    if(lista_vazia(l)){
        printf("Lista Vazia!!!\n");
    }else{
        printf("Lista(%d): \n",tamanho_lista(l));
        while(aux!=NULL){
            if(aux->ant!=NULL && aux->prox!=NULL){
                printf("%d<---|%d|--->%d \n",aux->ant->info,aux->info,aux->prox->info);
            }else{
                if(aux->ant==NULL && aux->prox==NULL)
                    printf("%d<---|%d|--->%d \n",0,aux->info,0);
                else if(aux->ant==NULL && aux->prox!=NULL)
                    printf("%d<---|%d|--->%d \n",0,aux->info,aux->prox->info);
                else{
                    printf("%d<---|%d|--->%d \n",aux->ant->info,aux->info,0);
                }
            }
            aux = aux->prox;
        }
    }
    printf("\n");
}

void mostrar_lista_inversa(ListaDupla *l){
      No* aux = l->fim;
    if(lista_vazia(l)){
        printf("Lista Vazia!!!\n");
    }else{
        printf("Lista(%d): ",tamanho_lista(l));
        while(aux!=NULL){
            printf("%d, ",aux->info);
            aux = aux->ant;
        }
    }
    printf("\n");
}

void adicionar_inicio(ListaDupla *l, int v){
    No* novo = criar_no(v);
    if(lista_vazia(l)){
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
}

void adicionar_fim(ListaDupla *l, int v){
    No* novo = criar_no(v);
    if(lista_vazia(l)){
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->ant = l->fim;
        l->fim->prox = novo;
        l->fim = novo;
    }

}

void adicionar_meio(No *n, int v){
    No* novo = criar_no(v);
    novo->prox = n->prox;
    novo->ant = n;
    n->prox->ant = novo;
    n->prox = novo;
}



No* retornar_no_pos(ListaDupla *l, int pos){
    int i;
    No *aux = l->inicio;
    if(pos < 0 || pos >= tamanho_lista(l)){
        printf("posicao invalida\n");
        return NULL;
    }
    for(i=0;i<pos;i++){
        aux=aux->prox;
    }
    return aux;
}

void adicionar_no_pos(ListaDupla *l, int v, int pos){
    No* n=NULL;
    if(pos==0){
        adicionar_inicio(l,v);
    }else if(pos == tamanho_lista(l)){
        adicionar_fim(l,v);
    }
    else{
        n = retornar_no_pos(l,pos-1);
        if(n!=NULL){
            adicionar_meio(n,v);
        }
    }
}

int del_primeiro_no(ListaDupla *l){
    int aux;
    No* no = l->inicio;
    if(lista_vazia(l)){
        printf("Erro: lista vazia\n");
        return -1;
    }
    l->inicio = no->prox;
    if(l->inicio==NULL){
        l->fim = NULL;
    }else{
        l->inicio->ant = NULL;
    }
    aux = no->info;
    free(no);
    return aux;
}


int del_ultimo_no(ListaDupla *l){
    int aux;
    No* no = l->fim;
    if(lista_vazia(l)){
        printf("Erro: lista vazia\n");
        return -1;
    }
    l->fim = no->ant;
    if(l->fim==NULL){
        l->inicio = NULL;
    }else{
        l->fim->prox = NULL;
    }
    aux = no->info;
    free(no);
    return aux;
}


int del_no_lista(No *ant){
    int aux;
    No *no;
    if(ant==NULL){
        printf("O no a ser excluido nao existe\n");
        return -1;
    }
    no = ant->prox;
    if(no==NULL){
        printf("O no a ser excluido nao existe\n");
        return -1;
    }
    ant->prox = no->prox;
    if(no->prox!=NULL)
        no->prox->ant = ant;
    aux = info_no(no);
    free(no);
    return aux;
}

int del_no_pos(ListaDupla *l, int pos){
    if(pos==0){
        return del_primeiro_no(l);
    }
    else if(pos==tamanho_lista(l) -1){
        del_ultimo_no(l);
    }
    else{
        if(pos < 1 || pos >=tamanho_lista(l)){
            printf("Posicao invalida\n");
            return -1;
        }
        No *n = retornar_no_pos(l,pos-1);
        return del_no_lista(n);
    }
}

int indice_no(ListaDupla *l, int v){
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

int del_no_valor(ListaDupla *l, int v){
    int pos = indice_no(l,v);
    return del_no_pos(l,pos);
}

int del_maior_no(ListaDupla *l){
    int aux, maior = l->inicio->info;
    No* n = l->inicio;

    while(n!=NULL){
        if(n->info>maior){
            maior = n->info;
        }
        n=n->prox;
    }
    return del_no_valor(l,maior);
}

//========================================================

void inverter_lista(ListaDupla *l){

    int aux[N];
    int i = 0, i2;

    No* num = l->inicio;

    while(num!=NULL){

        aux[i] = info_no(num);
        num = num->prox;

        i++;
    }

    i2 = i;

    while(i>0){
    
        del_primeiro_no(l);

        i--;
    }

    i = 0;

    while(tamanho_lista(l) < i2){
    
        adicionar_inicio(l,aux[i]);

        i++;
    }

    mostrar_lista(l);
}


void inserir_par_impar(ListaDupla *l){

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
    
        del_primeiro_no(l);

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

    while(i_impar > 0){

        aux[i] = impares[i_impar-1];

        i_impar--;

        i++;
    }

    while(i_par > 0){

        aux[i] = pares[i_par-1];

        i_par--;

        i++;

    }

    i2 = i;

    i = 0;

    while(tamanho_lista(l) < i2){
    
        adicionar_inicio(l,aux[i]);

        i++;
    }

    mostrar_lista(l);

}


void troca(int *x, int *y) {
    
    int aux;
    
    aux = *x;
    *x = *y;
    *y = aux;
}

void bubble_lista(ListaDupla *l){

    int aux[N];
    int i = 0, j;
    int tam = tamanho_lista(l);

    No* num = l->inicio;

    while(num!=NULL){

        aux[i] = info_no(num);
        num = num->prox;

        i++;
    }

    while(i>0){
    
        del_primeiro_no(l);

        i--;
    }

    for(i=0;i<6;i++){
        
        for(j=1;j<6;j++){
            
            if(aux[j-1] > aux[j]){
                
                troca(&aux[j], &aux[j-1]);
            }
        }
    }

    while(tam > 0){
    
        adicionar_inicio(l,aux[tam-1]);

        tam--;
    }
}

void inserir_ordenado(ListaDupla *l, int v){

    bubble_lista(l);

    No* ant = NULL;
    No* p = l->inicio;

    while(p!=NULL && p->info < v){
        ant = p;
        p=p->prox;
    }

    No *novo = criar_no(v);
    if(ant==NULL){
        novo->prox = l->inicio;
        l->inicio = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    mostrar_lista(l);
}

void transformar_decrescente(ListaDupla *l){

    bubble_lista(l);

    inverter_lista(l);
}

void remover_maior(ListaDupla *l){

    bubble_lista(l);

    del_ultimo_no(l);

    mostrar_lista(l);
}

int main(){

    ListaDupla *l = criar_lista();

    adicionar_inicio(l,47);
    
    adicionar_inicio(l,4);

    adicionar_inicio(l,47);

    adicionar_inicio(l,11);

    adicionar_inicio(l,4);

    adicionar_inicio(l,7);

    mostrar_lista(l);

    //inverter_lista(l);

    //inserir_par_impar(l);

    //inserir_ordenado(l, 20);

    //transformar_decrescente(l);

    remover_maior(l);

    return -1;
}
