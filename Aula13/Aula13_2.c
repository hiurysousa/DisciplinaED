#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
    float x;
    float y;
};

typedef struct ponto Ponto; // OPICIONAL


void imprime(Ponto *p);
void lerPonto(Ponto *p);
Ponto *criarPonto();
float distancia(Ponto *p, Ponto *q);

int main(){

    Ponto *p1 = criarPonto(); // Ou Struct ponto p -> SEM O TYPEDEF LÁ EM CIMA

    lerPonto(p1);

    imprime(p1);
    printf("A distancia entre os pontos e: %.2f", distancia(p1, p2)); // CRIAR P2 depois.
    free(p1);

    return 0;
}

Ponto *criarPonto(){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    if(!p){
        printf("Impossivel alocar.");
        exit(1);
    }
    return p;
}

void imprime(Ponto *p){
    printf("\nPonto fornecido: (%.2f, %.2f)", p->x, p->y);
}

void lerPonto(Ponto *p){
    printf("Digite as coordernadas do ponto(x, y): ");
    scanf("%f %f", &p->x, &p->y);
}

float distancia(Ponto *p, Ponto *q){
    return sqrt(pow(q->x - p->x, 2) + pow(p->y - q->y, 2));
}