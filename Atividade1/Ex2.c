#include <stdio.h>
#include <stdlib.h>

void percentualGastos(float despesa[5], float total){

    float gasto;
    int cont;

    for(cont = 0; cont < 5; cont++){

        gasto = (despesa[cont]/ total * 100);

        printf("A %d despesa equivale a %.2fporcento da despesa total.\n",cont+1,gasto);
    }

}

int main(){

    float despesa[5], total;
    int cont;

    for(cont = 0; cont < 5; cont++){
        printf("Digite a %d despesa: ",cont+1);
        scanf("%f",&despesa[cont]);
        total = total + despesa[cont];
    }

    percentualGastos(despesa, total);

    return 0;
}