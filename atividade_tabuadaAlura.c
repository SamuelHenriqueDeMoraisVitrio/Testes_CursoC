#include <stdio.h>
#include <stdlib.h>

void tabuada(int *numeroI){
    short numT = 0;

    while(numT < 10){
        numT++;
        short numRI = *numeroI;
        short resultado = (*numeroI) * numT;
        printf("\n %d * %d = %d\n", numRI, numT, resultado);
    }
    
}

int main(){
    printf("\n\nEscreva um numero inteiro\n\n");

    int numI;
    scanf(" %d", &numI);

    system("clear");

    tabuada(&numI);
}