#include <stdio.h>

// protótipo

int fatorial(int n);


int main() {
    int num = 0;

    printf("\nDigite um número: ");
    scanf("%d%*c", &num);

    printf("\n%d!= %d\n", num, fatorial(num));
    
    return 0;
}

int fatorial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n ; i++){
        resultado*=i;
    }
    return resultado;
}