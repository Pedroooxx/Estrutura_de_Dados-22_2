#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char x = 'P', *charp;
    int y = 10, *intp;
    float z = 1.5, *floatp;

    charp = &x;
    intp = &y;
    floatp = &z;

    *charp = 'J';
    *intp = 20;
    *floatp = 5.25;

    printf("%c\n",*charp);
    printf("%d\n",*intp);
    printf("%.2f\n",*floatp);

    return 0;
}