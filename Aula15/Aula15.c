#include <stdio.h>
#include <math.h>

struct ponto{
    float x;
    float y;
};

typedef struct ponto Ponto; // OPICIONAL

float area(int n, Ponto *p);

int main(){

    Ponto p[3] = {{1.0, 1.0}, {5.0, 1.0}, {4.0, 3.0}};
    printf("Area = %f\n", area(3,p));


    return 0;
}

float area(int n, Ponto *p){
    int i, j;
    float a = 0;
    for (i = 0; i < n; i++){
        j = (i+1) % n;
        a += (p[j].x-p[i].x)*(p[i].y + p[j].y)/2;
    }
    return fabs(a);
}