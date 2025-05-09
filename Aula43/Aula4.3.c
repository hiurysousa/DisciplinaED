#include <stdio.h>

int main(){
    int numeros[] = {3, 7, 15, 9, 22, 10};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int busca = 3;
    int encontrado = 0;

    for(int i = 0; i < tamanho; i++){
        if(numeros[i] == busca) {
            printf("Numero %d encontrado na posicao %d.\n", busca, i);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("numero %d nao encontrado.\n", busca);
    }

    return 0 ;
}