
/*ALOCAÇÃO DINAMICA*/
#include <stdio.h>
#include <stdlib.h>

float media(int n, float *v);
float variancia(int n, float *v);

int main(void){

    int n = 0;
    float med, var;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    float *vet = (float*)malloc(n * sizeof(float)); //bytes. Entrega o primeiro endereço dos 40 // chamado ponteiro para void(ponteiro nao definido: por isso faz o cast)

    if(vet == NULL){
        printf("Nao temos memoria suficiente para trabalhar com %d floats...");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Digite o valor do elemento %d: ", i+1);
        scanf("%f", &vet[i]);
    }   

    for(int i = 0; i < n; i++){
        printf("\n%.2f", vet[i]);
    }

    med = media(n, vet);
    printf("\nMedia = %.2f", med);

    var = variancia(n,vet);
    printf("\nVariancia = %.2f", var);

    return 0;

}

float media(int n, float *v){
    float media = 0.0;

    for(int i = 0; i < n; i++){
        media+=v[i];
    }
    return media/(float)n;
}

float variancia(int n, float *v){
    float soma = 0.0;
    float med = media(n, v);

    for (int i = 0; i < n; i++){
        soma += (v[i] - med)*(v[i] - med);
    }
    return soma/(float)n;
}

/* numero - media ao quadrado, soma tudo e divide pela qntd */