#include <stdio.h>
#include <stdlib.h>

#define N 9

int buscaSeq(int vet[], int key){
    for (int i=0; i<N; i++){
    //for (int i=0; i<N && vet[i]<= key; i++){
        if(vet[i] == key)
            return i;
    }
    return -1;
}
void imprime(int vet[]){
    int i;
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

    int vet[N] = {5,25,10,6,11,8,4,3};
    int num;

    printf("Digite um numero: ");
    scanf("%d",&num);

    imprime(vet);

    quicksort(vet,0,N-1);

    int resp = buscaSeq(vet, num);

    printf("\nApós o Quiksort: ");

    imprime(vet);

    if(resp == -1){
        printf("\nValor não encontrado.");
    }
    else{
        printf("\nEncontra-se na posição: %d",resp+1);
    }

    return 0;
}