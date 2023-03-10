#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
    int dia, mes, ano;

} Data;

Data *criarData(int dia, int mes, int ano) {
    Data *t = (Data *) malloc(sizeof(Data));
    t->dia = dia;
    t->mes = mes;
    t->ano = ano;
    return t;
}

Data *lerData() {

    int dia, mes, ano;

    printf("\nDigite o dia: ");
    scanf("%d", &dia);

    printf("\nDigite o mes: ");
    scanf("%d", &mes);

    printf("\nDigite o ano: ");
    scanf("%d", &ano);

    return criarData(dia, mes, ano);
}

void apresentarData(Data *t) {

    printf("\n%d/%d/%d\n", t->dia, t->mes, t->ano, "\n");
    
}

int main()
{
    Data *t;

    t = lerData();

    apresentarData(t);

    return 0;
}