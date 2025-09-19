#include <stdio.h>


typedef float Vetor[2];

int main(){

    Vetor ponto;

    ponto[0] = 1;
    ponto[1] = 4.5;

    printf("\n%.2f %.2f", ponto[0], ponto[1]);

    return 0;
}