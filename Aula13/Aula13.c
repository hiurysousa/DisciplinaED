#include <stdio.h>

struct ponto{
    float x[2];
    float y[2];
};

typedef struct ponto Ponto; // OPICIONAL

int main(){

    Ponto p; // Ou Struct ponto p -> SEM O TYPEDEF LÁ EM CIMA

    for(int i = 0; i < 2; i++){
        printf("Digite as coordernadas do ponto(x, y): ");
        scanf("%f %f", &p.x[i], &p.y[i]);
    }

    for (int i = 0; i < 2; i++){
        printf("\nPonto fornecido: (%.2f, %.2f)", p.x[i], p.y[i]);
    }


    return 0;
}