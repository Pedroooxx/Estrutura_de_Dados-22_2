#include <stdio.h>
#include <stdlib.h>

void subtrair(int a[10], int b[10]){

    int c[10], cont;

    for(cont = 0; cont < 10; cont++){
    c[cont] = a[cont] - b[cont];
    printf("%d - %d = %d\n",a[cont],b[cont],c[cont]);
    }

}
int main(){

    int a[10], b[10], cont;

    for(cont = 0; cont < 10; cont++){
        printf("Digite o %d numero do vetor A: ",cont+1);
        scanf("%d",&a[cont]);
        printf("Digite o %d numero do vetor B: ",cont+1);
        scanf("%d",&b[cont]);
    }

    subtrair(a,b);

    return 0;
}