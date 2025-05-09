#include <stdio.h>

int main () {
    /*
    if (op == 's' || op == 'S'){
        printf("prosseguir...\n");
    } else {
        if (op == 'n' || op == 'N')
            printf("finalizar o programa...\n");
        else 
            printf("Nao entendi... \n");
    }
    */
    char op = 'i';

    do{
        printf("Voce gostaria de prosseguir com a execucao? (s/n)");
        scanf("%c%*c", &op);        

    }while (op != 's' && op != 'S' && op != 'n' && op != 'N');
    printf("O usuario decidiu ");

    switch (op)
    {
        case 's':
        case 'S':
            printf("prosseguir...");
            break;
        case 'n':
        case 'N':
            printf("finalizar o programa...\n");
            break;

        default:
            printf("Nao entendi...");
    }

    return 0;
}