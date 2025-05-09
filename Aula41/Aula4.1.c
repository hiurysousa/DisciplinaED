#include <stdio.h>

/* uso do while */
int main(){
    char op = 'i';

    do {
        printf("Voce gostaria de prosseguir com a execucao? (s/n)");
        scanf("%c%*c", &op);        

    }while (op != 's' && op != 'S' && op != 'n' && op != 'N');
    printf("O usuario decidiu ");
    
    if (op == 's' || op == 'S'){
        printf("prosseguir...\n");
    } else {
        if (op == 'n' || op == 'N')
            printf("finalizar o programa...\n");
        else 
            printf("Nao entendi... \n");
    }

    return 0;
}