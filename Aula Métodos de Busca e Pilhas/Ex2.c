#include <stdio.h>
#include <stdlib.h>

#define N 10

int buscaBinaria(int vet[],int key,int left, int right)
{
        if(left > right)
            return -1;

        int mid = (left+right)/2;

        if(key == vet[mid])
            return mid;

        else if(key < vet[mid]) //
            return buscaBinaria(vet, key,mid+1, right);

        else
            return buscaBinaria(vet,key,left, mid-1);
}

// FUNÇÕES DA ORDENAÇÃO ==================================================

void bubble(int vet[]) {
    int i, j;
    for (i=0; i<N-1; i++) {
        for(j=1; j<N-i; j++){
            if (vet[j-1] < vet[j]) {

            troca(&vet[j], &vet[j-1]);
            }
        }
    }
}
void troca(int *x, int *y){

    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
void imprime(int vet[]){
    int i;
    printf("\n");
    for (i=0; i<N; i++)
    {
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

//===================================================================

int main(){

    int vet[N];
    int num;

    for (int i = 0; i < N; i++)
    {
    vet[i] = rand() % 100;
    }

    imprime(vet);

    bubble(vet);

    printf("\nApós o Bubble Sort: ");
    imprime(vet);

    printf("\nDigite um valor para encontrar: ");
    scanf("%d",&num);

    int resp = buscaBinaria(vet, num, 0, N-1);

    if(resp < 0){
        printf("\nBUSCA BINARIA - Valor nao encontrado.");
    }
    else{
        printf("\nBUSCA BINARIA - Encontra-se na posicao: %d \n\n",resp+1);
    }

    return 0;
}