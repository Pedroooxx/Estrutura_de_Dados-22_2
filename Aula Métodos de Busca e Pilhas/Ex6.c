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

void inverte_palavras(Pilha *p, int comp){

    char aux[N], auxi;
    int espaco[N], esp_cont = 1;
    int esq, dir;
    int i;

    espaco[0] = 0;

    for(i = 0; i <= comp - 1; i++){

        if(p->vet[i] == ' '){

            espaco[esp_cont] = i;
            esp_cont++;
        }
    }
    espaco[esp_cont] = comp-1;

    i = 0;

    for(esp_cont == esp_cont; esp_cont > 0; esp_cont--){

        dir = espaco[esp_cont];
        esq = espaco[esp_cont-1];

            if(p->vet[esq] == ' '){
                esq++;
            }

            if(p->vet[dir] == ' '){
                aux[dir] = ' ';
                dir--;
            }

        do{

            auxi = p->vet[dir];
            aux[dir] = p->vet[esq];
            aux[esq] = auxi;

            dir--;
            esq++;

            i++;

        }while(esq != dir && dir >= esq);
        aux[dir] = p->vet[esq];
    }
    for(i = 0; i < comp; i++){
        pilha_pop(p);
    }
    for(i = 0; i < comp; i++){
        pilha_push(p, aux[i]);
    }
}

int main(){

    int i = 0, comp;

    char frase[N] = {"ESTE EXERCICIO E MUITO FACIL"};
    Pilha *p;
    p = criar_pilha();

    while(frase[i] != '\0'){

        pilha_push(p, frase[i]);

        i++;
    }

    imprimir_pilha(p);

    comp = i;
    
    inverte_palavras(p, comp);

    printf("\n");
    imprimir_pilha(p);

    return -1;
}