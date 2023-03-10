#include <stdio.h>
#include <stdlib.h>

#define N 1000

int buscaSeq(int vet[], int key){

    int i;

    printf("\n");

    for (i=0; i<N; i++){
    //for (int i=0; i<N && vet[i]<= key; i++){
        if(vet[i] == key)
            return i+1;
    }

    return -1;
}
int buscaBinariaIterativo(int vet[],int key,int left, int right)
{
    int mid, i=0;

    printf("\n");

    while(left<=right)
    {
        i++;
        mid = (left+right)/2;
        if(key == vet[mid]){
            printf("\nBusca Binaria - Repeticoes: %d \n", i+1);
            return mid;
        }
        else if(key < vet[mid])
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
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

// FUNÇÕES DA ORDENAÇÃO ==================================================
void quicksort(int vet[], int left, int right){

    int pivot;
    if (left >= right)
    {
        return;
    }
    pivot = partition(vet, left, right);
    quicksort(vet, left, pivot-1);
    quicksort(vet, pivot+1, right);
}
int partition(int vet[], int left, int right){

    int i = left + 1, j = right;

    while(i<=j)
    {
        while (vet[i] <= vet[left] && i <= right) i++;
        while (vet[j] > vet[left] && j > left) j--;

        if (i < j) troca(&vet[i], &vet[j]);
    }
    troca(&vet[j], &vet[left]);

    return j;
}
void troca(int *x, int *y){

    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
//===================================================================


int main(){

    int vet[N];
    int num;

    for (int i = 0; i < N; i++)
    {
    vet[i] = rand() % 10000;
    }

    imprime(vet);

    quicksort(vet,0,N-1);

    printf("\nApós o Quiksort: ");
    imprime(vet);

    printf("\nDigite um valor para encontrar: ");
    scanf("%d",&num);

    int resp1 = buscaSeq(vet, num);
    int resp2 = buscaBinariaIterativo(vet, num, 0, N-1);

    if(resp1 < 0){
        printf("\nBUSCA SEQUENCIAL - Valor nao encontrado.");
    }
    else{
        printf("BUSCA SEQUENCIAL - Repeticoes: %d \n", resp1);
        printf("\nBUSCA SEQUENCIAL - Encontra-se na posicao: %d",resp1);
    }
    if(resp2 < 0){
        printf("\nBUSCA BINARIA - Valor nao encontrado.");
    }
    else{
        printf("\nBUSCA BINARIA - Encontra-se na posicao: %d \n\n",resp2+1);
    }

    return 0;
}