#include <stdio.h>
#include <math.h>

struct ponto{
    float x;
    float y;
} Ponto;

typedef struct ponto Ponto; // OPICIONAL

typedef struct circulo{
    Ponto centro;
    float raio;
} Circulo;

float distancia(Ponto *p1, Ponto *p2);
int interior(Circulo *c, Ponto *p);
Ponto centro_geom(int n, Ponto *v);

int main(){
    Ponto p;

    p.x = 1.0;
    p.y = 2.3;

    Circulo cir;

    cir.centro.x = 1.0;
    cir.centro.y = 1.5;
    cir.raio = 10;

    printf("O ponto p(%.2f, %.2f) é: ");
    if (interior(&cir, &p)){
        printf("Interior ")
    } else {
        printf("Exterior");
        printf(" ao circulo centro(%.2f, %.2f) e raio %.2f.",
    }

    return 0;
}

float distancia(Ponto *p1, Ponto *p2){
    return sqrt(pow(p1->x - p2->x, 2) + pow(p2->y - p1->y, 2));
}

int interior(Circulo *c, Ponto *p){
    return distancia(&c->centro, p) < c->raio;
}

Ponto centro_geom(int n, Ponto *v){
    int i;
    Ponto p = {0.0f, 0.0f};
    for (i = 0; i < n; i++){
        p.x += v[i].x;
        p.y += v[i].y;
    }

    p.x /= n;
    p.y /= n;

    return p;
}