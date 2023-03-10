#include<stdio.h>
#include<stdlib.h>

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

No* adicionar_novo_no(No *n, int v){
    No *novo = criar_no(v);
    novo->prox = n->prox;
    n->prox = novo;
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

No* retornar_no_pos(Lista *l, int pos){
    int i;
    No *aux = l->inicio;
    if(pos < 0 || pos >= tamanho_lista(l)){
        return NULL;
    }
    for(i=0;i<pos;i++){
        aux=aux->prox;
    }
    return aux;
}

No* adicionar_no_pos(Lista *l, int v, int pos){
    if(pos==0){
        adicionar_inicio(l,v);
    }else{
        No* n = retornar_no_pos(l,pos-1);
        if(n!=NULL){
            n = adicionar_novo_no(n,v);
        }
        return n;
    }
}

int del_primeiro_no(Lista *l){
    int aux;
    No* no = l->inicio;
    if(lista_vazia(l)){
        printf("Erro: Lista vazia\n");
        return -1;
    }
    l->inicio = no->prox;
    aux = info_no(no);
    free(no);
    return aux;
}

int del_no_lista(No *ant){
    int aux;
    No *no = ant->prox;
    if(no==NULL){
        printf("O no a ser excluido nao existe!!\n");
        return -1;
    }
    ant->prox = no->prox;
    aux = info_no(no);
    free(no);
    return aux;
}

int del_no_pos(Lista *l, int pos){
    if(pos==0){
        return del_primeiro_no(l);
    }
    else{
        if(pos < 1 || pos >=tamanho_lista(l)){
            printf("Posi��o inv�lida\n");
            return -1;
        }
        No *n = retornar_no_pos(l,pos-1);
        return del_no_lista(n);
    }
}

int del_no_valor(Lista *l, int v){
    int pos = indice_no(l,v);
    if(pos==0){
        del_primeiro_no(l);
    }else if(pos > 0){
        del_no_pos(l,pos);
    }
    return pos;
}

void inserir_ordenado(Lista *l, int v){
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
}

//========================================================

void inverter_lista(Lista *l){

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

    while(tamanho_lista(l) < i2){
    
        adicionar_inicio(l,aux[i]);

        i++;
    }

    mostrar_lista(l);

}

void inserir_qualquer_lugar(Lista *l){

    int p, v;

    printf("Digite o valor que gostaria de inserir na lista:");
    scanf("%d",&v);

    printf("Digite a posiçao em que deseja inseri-la:");
    scanf("%d",&p);

    adicionar_no_pos(l, v, p);
}

void somar(Lista *l){

    int i = 0, soma = 0;

    No* num = l->inicio;

    while(num){

        soma = soma + info_no(num);
        num = num->prox;

        i++;
    }
    printf("Soma da lista = %d\n\n",soma);
}

void menor_valor(Lista *l){

    int aux[N];
    int i = 0, menor;

    No* num = l->inicio;

    while(num!=NULL){

        aux[i] = info_no(num);
        num = num->prox;

        i++;
    }

    menor = aux[0];

    for(i = 1; i < tamanho_lista(l); i++){

        if(menor > aux[i]){

            menor = aux[i];
        }
    }
    printf("Menor da lista: %d\n\n",menor);
}

void troca(int *x, int *y) {
    
    int aux;
    
    aux = *x;
    *x = *y;
    *y = aux;
}

void bubble_lista(Lista *l){

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

void intercalar_listas(Lista *l, Lista *l2, Lista *lf){

    No* nl = l->inicio;
    No* nl2 = l2->inicio;

    while(tamanho_lista(lf) < (tamanho_lista(l) + tamanho_lista(l2))){

        if(info_no(nl) != NULL){
            adicionar_inicio(lf,info_no(nl));
            nl = nl->prox;
        }
        if(info_no(nl2) != NULL){
            adicionar_inicio(lf,info_no(nl2));
            nl2 = nl2->prox;
        }
    }
}

void retirar_repetidos(Lista *l){

    int aux[N];
    int i = 0, i2 = 0;

    No* num = l->inicio;

    while(num!=NULL){

        aux[i] = info_no(num);
        num = num->prox;

        i++;
    }

    for(i = 0; i< tamanho_lista(l); i++){

        for(i2 = tamanho_lista(l); i2 > 0; i2--){

            if(aux[i2] == aux[i] && i != i2){

                del_no_valor(l, aux[i2]);
            }
        }
    }
}

void tamanho_listaEncad(Lista *l){

    int tam = 0;

    No* num = l->inicio;

    while(num!=NULL){
        
        num = num->prox;
        tam++;
    }
    printf("/nTamanho da lista encadeada: %d\n\n",tam);
}

int main(){

    int op;

    Lista *l = criar_lista();
    Lista *l2 = criar_lista();
    Lista *lf = criar_lista();

    adicionar_inicio(l,47);
    
    adicionar_inicio(l,4);

    adicionar_inicio(l,47);

    adicionar_inicio(l,11);

    adicionar_inicio(l,4);

    adicionar_inicio(l,7);

    adicionar_inicio(l2,5);
    
    adicionar_inicio(l2,23);

    adicionar_inicio(l2,32);

    adicionar_inicio(l2,6);

    adicionar_inicio(l2,29);

    adicionar_inicio(l2,12);

    printf("***MENU DE OPCOES***");
    printf("\nINVERTER LISTA - 1");
    printf("\nORDENA PARES/IMPARES - 2");
    printf("\nINSERE EM QUALQUER LUGAR - 3");
    printf("\nSOMA A LISTA - 4");
    printf("\nBUSCA O MENOR VALOR - 5");
    printf("\nBUBBLE SORT DA LISTA - 6");
    printf("\nINTERCALA DUAS LISTAS - 7");
    printf("\nRETIRA REPETIDOS - 8");
    printf("\nGERA O TAMANHO DA LISTA - 9");
    printf("\n--->");
    scanf("%d",op);

    mostrar_lista(l);

    switch (op){

        case 1:
            inverter_lista(l);
            break;
        case 2:
            inserir_par_impar(l);
            break;
        case 3:
            inserir_qualquer_lugar(l);
            break;
        case 4:
            somar(l);
            break;
        case 5:
            menor_valor(l);
            break;
        case 6:
            bubble_lista(l);
            break;
        case 7:
            intercalar_listas(l,l2,lf);
            break;
        case 8:
            retirar_repetidos(l);
            break;
        case 9:
            tamanho_listaEncad(l);
            break;
    }
    mostrar_lista(l);
    
    return -1;
}