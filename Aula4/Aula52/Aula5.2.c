#include <stdio.h>

// protótipo

int fatorial(int n);


int main(int argc, char *argv[]) {
    switch(argc){
        case 1:
            printf("\nVoce nao entrou com os operandos...");
            break;
        
        case 2:
            printf("\nFaltou o segundo operando...");
            break;
        case 3:
            float a = atof(argv[1]);
            float b = atof(argv[2]);
            
    }
}

int fatorial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n ; i++){
        resultado*=i;
    }
    return resultado;
}